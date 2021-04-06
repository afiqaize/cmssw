#include "RecoEgamma/EgammaElectronAlgos/interface/ElectronHcalHelper.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Framework/interface/ConsumesCollector.h"

using namespace reco;

ElectronHcalHelper::ElectronHcalHelper(const Configuration& cfg, edm::ConsumesCollector&& cc) : cfg_(cfg) {
  if (cfg_.hOverEConeSize == 0) {
    return;
  }

  caloGeometryToken_ = cc.esConsumes();
}

void ElectronHcalHelper::beginEvent(const edm::Event& evt, const edm::EventSetup& eventSetup) {
  if (cfg_.hOverEConeSize == 0) {
    return;
  }

  hcalIso_ = std::make_unique<EgammaHcalIsolation>(cfg_.hOverEConeSize,
                                                   0.,
                                                   cfg_.eThresHB,
                                                   std::array<double, 4>{{0., 0., 0., 0.}},
                                                   cfg_.eThresHE,
                                                   std::array<double, 7>{{0., 0., 0., 0., 0., 0., 0.}},
                                                   eventSetup.getHandle(caloGeometryToken_),
                                                   evt.get(cfg_.hcalRecHits));
}

double ElectronHcalHelper::hcalESum(const SuperCluster& sc, int depth) const {
  return (cfg_.hOverEConeSize != 0.) ? hcalIso_->getHcalESum(&sc, depth) : 0.;
}
