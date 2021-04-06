//*****************************************************************************
// File:      EgammaHcalIsolation.cc
// ----------------------------------------------------------------------------
// OrigAuth:  Matthias Mozer
// Institute: IIHE-VUB
//=============================================================================
//*****************************************************************************
//ROOT includes
#include <Math/VectorUtil.h>

//CMSSW includes
#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaHcalIsolation.h"
#include "DataFormats/HcalDetId/interface/HcalDetId.h"
#include "Geometry/CommonDetUnit/interface/TrackingGeometry.h"
#include "Geometry/Records/interface/TrackerDigiGeometryRecord.h"
#include "DataFormats/RecoCandidate/interface/RecoCandidate.h"

using namespace std;

double scaleToE(const double& eta) { return 1.0; }
double scaleToEt(const double& eta) { return sin(2 * atan(exp(-eta))); }

EgammaHcalIsolation::EgammaHcalIsolation(double extRadius,
                                         double intRadius,
                                         const std::array<double, 4> &eThresHB,
                                         const std::array<double, 4> &etThresHB,
                                         const std::array<double, 7> &eThresHE,
                                         const std::array<double, 7> &etThresHE,
                                         edm::ESHandle<CaloGeometry> theCaloGeom,
                                         const HBHERecHitCollection& mhbhe) : extRadius_(extRadius),
                                                                              intRadius_(intRadius),
                                                                              caloGeometry_(*theCaloGeom.product()),
                                                                              mhbhe_(mhbhe)
{
  eThresHB_ = eThresHB;
  etThresHB_ = etThresHB;
  eThresHE_ = eThresHE;
  etThresHE_ = etThresHE;

  // set up the geometry and selector
  doubleConeSel_ = std::make_unique<CaloDualConeSelector<HBHERecHit>>(intRadius_, extRadius_, &caloGeometry_, DetId::Hcal);
}

EgammaHcalIsolation::EgammaHcalIsolation(double extRadius,
                                         double intRadius,
                                         const std::array<double, 4> &eThresHB,
                                         const std::array<double, 4> &etThresHB,
                                         const std::array<double, 7> &eThresHE,
                                         const std::array<double, 7> &etThresHE,
                                         const CaloGeometry &caloGeometry,
                                         const HBHERecHitCollection& mhbhe) : extRadius_(extRadius),
                                                                              intRadius_(intRadius),
                                                                              caloGeometry_(caloGeometry),
                                                                              mhbhe_(mhbhe)
{
  eThresHB_ = eThresHB;
  etThresHB_ = etThresHB;
  eThresHE_ = eThresHE;
  etThresHE_ = etThresHE;

  // set up the geometry and selector
  doubleConeSel_ = std::make_unique<CaloDualConeSelector<HBHERecHit>>(intRadius_, extRadius_, &caloGeometry_, DetId::Hcal);
}

double EgammaHcalIsolation::getHcalSum(const GlobalPoint& pclu,
                                       int depth,
                                       double (*scale)(const double&)) const {
  double sum = 0.;
  if (!mhbhe_.empty()) {
    // Compute the HCAL energy behind ECAL
    doubleConeSel_->selectCallback(pclu, mhbhe_, [this, &sum, &depth, &scale] (const HBHERecHit& i) {
      double eta = caloGeometry_.getPosition(i.detid()).eta();
      HcalDetId hcalDetId(i.detid());
      const int hd = hcalDetId.depth();

      const bool right_depth = (depth == 0 or hd == depth);
      if (!right_depth)
        return;

      const bool goodHB = hcalDetId.subdet() == HcalBarrel and i.energy() > eThresHB_[hd - 1] and i.energy() * scaleToEt(eta) > etThresHB_[hd - 1];
      const bool goodHE = hcalDetId.subdet() == HcalEndcap and i.energy() > eThresHE_[hd - 1] and i.energy() * scaleToEt(eta) > etThresHE_[hd - 1];

      if (goodHB or goodHE)
        sum += i.energy() * scale(eta);
    });
  }

  return sum;
}
