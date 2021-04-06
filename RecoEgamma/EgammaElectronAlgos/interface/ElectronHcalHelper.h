#ifndef ElectronHcalHelper_h
#define ElectronHcalHelper_h

#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "RecoEgamma/EgammaIsolationAlgos/interface/EgammaHcalIsolation.h"

class ConsumesCollector;

class ElectronHcalHelper {
public:
  struct Configuration {
    // common parameters
    double hOverEConeSize;

    // specific parameters if use rechits
    edm::EDGetTokenT<HBHERecHitCollection> hcalRecHits;
    std::array<double, 4> eThresHB;
    std::array<double, 7> eThresHE;
  };

  ElectronHcalHelper(const Configuration &cfg, edm::ConsumesCollector &&cc);

  void beginEvent(const edm::Event &evt, const edm::EventSetup &eventSetup);

  double hcalESum(const reco::SuperCluster &, int depth) const;
  double hOverEConeSize() const { return cfg_.hOverEConeSize; }

private:
  const Configuration cfg_;

  edm::ESGetToken<CaloGeometry, CaloGeometryRecord> caloGeometryToken_;

  // event data (rechits strategy)
  std::unique_ptr<EgammaHcalIsolation> hcalIso_ = nullptr;
};

#endif
