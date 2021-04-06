#ifndef CutBasedPhotonIDAlgo_H
#define CutBasedPhotonIDAlgo_H

#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

class CutBasedPhotonIDAlgo {
public:
  CutBasedPhotonIDAlgo(){};

  virtual ~CutBasedPhotonIDAlgo(){};

  void setup(const edm::ParameterSet &conf);
  void decideEB(const reco::Photon *pho, bool &LooseEM, bool &LoosePhoton, bool &TightPhoton);
  void decideEE(const reco::Photon *pho, bool &LooseEM, bool &LoosePhoton, bool &TightPhoton);

private:
  //Which cuts to do?

  bool dophotonEcalRecHitIsolationCut_;
  bool dophotonHcalRecHitIsolationCut_;
  bool dophotonHCTrkIsolationCut_;
  bool dophotonSCTrkIsolationCut_;
  bool dophotonHCNTrkCut_;
  bool dophotonSCNTrkCut_;
  bool dorequireFiducial_;
  bool dophotonHadOverEMCut_;
  bool dophotonsigmaeeCut_;
  bool dophotonR9Cut_;

  double looseEMEcalIsoRelativeCutSlopeEB_;
  double looseEMEcalIsoRelativeCutOffsetEB_;
  double looseEMHcalRecHitIsolationCutSlopeEB_;
  double looseEMHcalRecHitIsolationCutOffsetEB_;
  double looseEMHollowConeTrkIsolationSlopeEB_;
  double looseEMHollowConeTrkIsolationOffsetEB_;
  double looseEMSolidConeTrkIsolationSlopeEB_;
  double looseEMSolidConeTrkIsolationOffsetEB_;
  double looseEMSolidConeTrkIsolationCutEB_;
  int looseEMSolidConeNTrkCutEB_;
  int looseEMHollowConeNTrkCutEB_;
  double looseEMEtaWidthCutEB_;
  double looseEMHadOverEMCutEB_;
  double looseEMR9CutEB_;

  double loosephotonEcalIsoRelativeCutSlopeEB_;
  double loosephotonEcalIsoRelativeCutOffsetEB_;
  double loosephotonHcalRecHitIsolationCutSlopeEB_;
  double loosephotonHcalRecHitIsolationCutOffsetEB_;
  double loosephotonHollowConeTrkIsolationSlopeEB_;
  double loosephotonHollowConeTrkIsolationOffsetEB_;
  double loosephotonSolidConeTrkIsolationSlopeEB_;
  double loosephotonSolidConeTrkIsolationOffsetEB_;
  double loosephotonSolidConeTrkIsolationCutEB_;
  int loosephotonSolidConeNTrkCutEB_;
  int loosephotonHollowConeNTrkCutEB_;
  double loosephotonEtaWidthCutEB_;
  double loosephotonHadOverEMCutEB_;
  double loosephotonR9CutEB_;

  double tightphotonEcalIsoRelativeCutSlopeEB_;
  double tightphotonEcalIsoRelativeCutOffsetEB_;
  double tightphotonHcalRecHitIsolationCutSlopeEB_;
  double tightphotonHcalRecHitIsolationCutOffsetEB_;
  double tightphotonHollowConeTrkIsolationSlopeEB_;
  double tightphotonHollowConeTrkIsolationOffsetEB_;
  double tightphotonSolidConeTrkIsolationSlopeEB_;
  double tightphotonSolidConeTrkIsolationOffsetEB_;
  double tightphotonSolidConeTrkIsolationCutEB_;
  int tightphotonSolidConeNTrkCutEB_;
  int tightphotonHollowConeNTrkCutEB_;
  double tightphotonEtaWidthCutEB_;
  double tightphotonHadOverEMCutEB_;
  double tightphotonR9CutEB_;

  double looseEMEcalIsoRelativeCutSlopeEE_;
  double looseEMEcalIsoRelativeCutOffsetEE_;
  double looseEMHcalRecHitIsolationCutSlopeEE_;
  double looseEMHcalRecHitIsolationCutOffsetEE_;
  double looseEMHollowConeTrkIsolationSlopeEE_;
  double looseEMHollowConeTrkIsolationOffsetEE_;
  double looseEMSolidConeTrkIsolationSlopeEE_;
  double looseEMSolidConeTrkIsolationOffsetEE_;
  double looseEMSolidConeTrkIsolationCutEE_;
  int looseEMSolidConeNTrkCutEE_;
  int looseEMHollowConeNTrkCutEE_;
  double looseEMEtaWidthCutEE_;
  double looseEMHadOverEMCutEE_;
  double looseEMR9CutEE_;

  double loosephotonEcalIsoRelativeCutSlopeEE_;
  double loosephotonEcalIsoRelativeCutOffsetEE_;
  double loosephotonHcalRecHitIsolationCutSlopeEE_;
  double loosephotonHcalRecHitIsolationCutOffsetEE_;
  double loosephotonHollowConeTrkIsolationSlopeEE_;
  double loosephotonHollowConeTrkIsolationOffsetEE_;
  double loosephotonSolidConeTrkIsolationSlopeEE_;
  double loosephotonSolidConeTrkIsolationOffsetEE_;
  double loosephotonSolidConeTrkIsolationCutEE_;
  int loosephotonSolidConeNTrkCutEE_;
  int loosephotonHollowConeNTrkCutEE_;
  double loosephotonEtaWidthCutEE_;
  double loosephotonHadOverEMCutEE_;
  double loosephotonR9CutEE_;

  double tightphotonEcalIsoRelativeCutSlopeEE_;
  double tightphotonEcalIsoRelativeCutOffsetEE_;
  double tightphotonHcalRecHitIsolationCutSlopeEE_;
  double tightphotonHcalRecHitIsolationCutOffsetEE_;
  double tightphotonHollowConeTrkIsolationSlopeEE_;
  double tightphotonHollowConeTrkIsolationOffsetEE_;
  double tightphotonSolidConeTrkIsolationSlopeEE_;
  double tightphotonSolidConeTrkIsolationOffsetEE_;
  double tightphotonSolidConeTrkIsolationCutEE_;
  int tightphotonSolidConeNTrkCutEE_;
  int tightphotonHollowConeNTrkCutEE_;
  double tightphotonEtaWidthCutEE_;
  double tightphotonHadOverEMCutEE_;
  double tightphotonR9CutEE_;
};

#endif  // CutBasedPhotonIDAlgo_H
