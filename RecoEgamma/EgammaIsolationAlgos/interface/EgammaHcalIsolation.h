#ifndef EgammaIsolationAlgos_EgammaHcalIsolation_h
#define EgammaIsolationAlgos_EgammaHcalIsolation_h
//*****************************************************************************
// File:      EgammaHcalIsolation.h
// ----------------------------------------------------------------------------
// OrigAuth:  Matthias Mozer
// Institute: IIHE-VUB
//=============================================================================
//*****************************************************************************

//C++ includes
#include <memory>
#include <vector>
#include <functional>

//CMSSW includes
#include "FWCore/Framework/interface/ESHandle.h"
#include "DataFormats/RecoCandidate/interface/RecoCandidate.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "RecoCaloTools/Selectors/interface/CaloDualConeSelector.h"
#include "DataFormats/GeometryVector/interface/GlobalPoint.h"
#include "DataFormats/GeometryVector/interface/GlobalVector.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"

//Sum helper functions
double scaleToE(const double &eta);
double scaleToEt(const double &eta);

class EgammaHcalIsolation {
public:
  //constructors
  EgammaHcalIsolation(double extRadius,
                      double intRadius,
                      const std::array<double, 4> &eThresHB,
                      const std::array<double, 4> &etThresHB,
                      const std::array<double, 7> &eThresHE,
                      const std::array<double, 7> &etThresHE,
                      edm::ESHandle<CaloGeometry> theCaloGeom,
                      const HBHERecHitCollection &mhbhe);

  EgammaHcalIsolation(double extRadius,
                      double intRadius,
                      const std::array<double, 4> &eThresHB,
                      const std::array<double, 4> &etThresHB,
                      const std::array<double, 7> &eThresHE,
                      const std::array<double, 7> &etThresHE,
                      const CaloGeometry &caloGeometry,
                      const HBHERecHitCollection &mhbhe);

  double getHcalESum(const reco::Candidate *c, int depth = 0) const { return getHcalESum(c->get<reco::SuperClusterRef>().get(), depth); }
  double getHcalEtSum(const reco::Candidate *c, int depth = 0) const { return getHcalEtSum(c->get<reco::SuperClusterRef>().get(), depth); }
  double getHcalESum(const reco::SuperCluster *sc, int depth = 0) const { return getHcalESum(sc->position(), depth); }
  double getHcalEtSum(const reco::SuperCluster *sc, int depth = 0) const { return getHcalEtSum(sc->position(), depth); }
  double getHcalESum(const math::XYZPoint &p, int depth = 0) const { return getHcalESum(GlobalPoint(p.x(), p.y(), p.z()), depth); }
  double getHcalEtSum(const math::XYZPoint &p, int depth = 0) const { return getHcalEtSum(GlobalPoint(p.x(), p.y(), p.z()), depth); }
  double getHcalESum(const GlobalPoint &pclu, int depth = 0) const { return getHcalSum(pclu, depth, &scaleToE); }
  double getHcalEtSum(const GlobalPoint &pclu, int depth = 0) const { return getHcalSum(pclu, depth, &scaleToEt); }

private:
  double getHcalSum(const GlobalPoint &pclu, int depth, double (*scale)(const double &)) const;

  double extRadius_;
  double intRadius_;
  std::array<double, 4> eThresHB_;
  std::array<double, 4> etThresHB_;
  std::array<double, 7> eThresHE_;
  std::array<double, 7> etThresHE_;

  const CaloGeometry &caloGeometry_;
  const HBHERecHitCollection &mhbhe_;

  std::unique_ptr<CaloDualConeSelector<HBHERecHit>> doubleConeSel_;
};

#endif
