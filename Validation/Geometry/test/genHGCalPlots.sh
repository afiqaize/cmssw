#!/bin/bash -ex

VGEO_DIR=$CMSSW_BASE/src/Validation/Geometry
TEST_DIR=${VGEO_DIR}/test/materialBudgetHGCalPlots

if [ -d $TEST_DIR ] ; then rm -rf $TEST_DIR ; fi
mkdir $TEST_DIR && cd $TEST_DIR

cmsRun ${VGEO_DIR}/test/single_neutrino_cfg.py nEvents=1000 >$TEST_DIR/single_neutrino_cfg.log 2>&1

for geom in {'Extended2026D49','Extended2026D62'}; do
    python ${VGEO_DIR}/test/runP_HGCal_cfg.py geom=$geom label=HGCal >$TEST_DIR/runP_HGCal_cfg_$geom.log 2>&1
    python ${VGEO_DIR}/test/MaterialBudgetHGCal.py -s -d HGCal
    mv ${TEST_DIR}/Images/HGCal_x_vs_eta.png ${TEST_DIR}/Images/HGCal_x_vs_eta_$geom.png 
    mv ${TEST_DIR}/Images/HGCal_l_vs_eta.png ${TEST_DIR}/Images/HGCal_l_vs_eta_$geom.png 
    mv ${TEST_DIR}/Images/HGCal_x_vs_phi.png ${TEST_DIR}/Images/HGCal_x_vs_phi_$geom.png 
    mv ${TEST_DIR}/Images/HGCal_l_vs_phi.png ${TEST_DIR}/Images/HGCal_l_vs_phi_$geom.png 
    mv ${TEST_DIR}/Images/HGCal_x_vs_z_vs_Rsum.png ${TEST_DIR}/Images/HGCal_x_vs_z_vs_Rsum_$geom.png 
    mv ${TEST_DIR}/Images/HGCal_l_vs_z_vs_Rsum.png ${TEST_DIR}/Images/HGCal_l_vs_z_vs_Rsum_$geom.png 
    mv ${TEST_DIR}/Images/HGCal_x_vs_z_vs_Rloc.png ${TEST_DIR}/Images/HGCal_x_vs_z_vs_Rloc_$geom.png 
    mv ${TEST_DIR}/Images/HGCal_l_vs_z_vs_Rloc.png ${TEST_DIR}/Images/HGCal_l_vs_z_vs_Rloc_$geom.png 
    mv ${TEST_DIR}/Images/HGCal_x_vs_z_vs_Rloccos.png ${TEST_DIR}/Images/HGCal_x_vs_z_vs_Rloccos_$geom.png 
    mv ${TEST_DIR}/Images/HGCal_l_vs_z_vs_Rloccos.png ${TEST_DIR}/Images/HGCal_l_vs_z_vs_Rloccos_$geom.png 
done


echo '<html> <head><title>Reference HGCAL Material Budget</title></head> <style>img.Reference{margin: 20px auto 20px auto; border: 10px solid green; border-radius: 10px;}img.PullRequest{margin: 20px auto 20px auto; border: 10px solid red; border-radius: 10px;}</style> <body> <h1>Reference Plots</h1> <p>Please check any diferences in the plots compared with the given reference. <en>Reference plots</en> have a green border followed by the output of the PR which features a red border</p><h2>Geometry: Extended2026D49</h2> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V11/HGCal_x_vs_eta.png" width="375"/> <img class="PullRequest" src="HGCal_x_vs_eta_Extended2026D49.png" width="375"/> <br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V11/HGCal_l_vs_eta.png" width="375"/> <img class="PullRequest" src="HGCal_l_vs_eta_Extended2026D49.png" width="375"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V11/HGCal_x_vs_phi.png" width="375"/> <img class="PullRequest" src="HGCal_x_vs_phi_Extended2026D49.png" width="375"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V11/HGCal_l_vs_phi.png" width="375"/> <img class="PullRequest" src="HGCal_l_vs_phi_Extended2026D49.png" width="375"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V11/HGCal_x_vs_z_vs_Rsum.png" width="1000"/> <img class="PullRequest" src="HGCal_x_vs_z_vs_Rsum_Extended2026D49.png" width="1000"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V11/HGCal_l_vs_z_vs_Rsum.png" width="1000"/> <img class="PullRequest" src="HGCal_l_vs_z_vs_Rsum_Extended2026D49.png" width="1000"/> <br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V11/HGCal_x_vs_z_vs_Rloc.png" width="1000"/> <img class="PullRequest" src="HGCal_x_vs_z_vs_Rloc_Extended2026D49.png" width="1000"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V11/HGCal_l_vs_z_vs_Rloc.png" width="1000"/> <img class="PullRequest" src="HGCal_l_vs_z_vs_Rloc_Extended2026D49.png" width="1000"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V11/HGCal_x_vs_z_vs_Rloccos.png" width="1000"/> <img class="PullRequest" src="HGCal_x_vs_z_vs_Rloccos_Extended2026D49.png" width="1000"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V11/HGCal_l_vs_z_vs_Rloccos.png" width="1000"/> <img class="PullRequest" src="HGCal_l_vs_z_vs_Rloccos_Extended2026D49.png" width="1000"/> <br/> <hr/> <h2>Geometry: Extended2026D62</h2> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V14/HGCal_x_vs_eta.png" width="375"/> <img class="PullRequest" src="HGCal_x_vs_eta_Extended2026D62.png" width="375"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V14/HGCal_l_vs_eta.png" width="375"/> <img class="PullRequest" src="HGCal_l_vs_eta_Extended2026D62.png" width="375"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V14/HGCal_x_vs_phi.png" width="375"/> <img class="PullRequest" src="HGCal_x_vs_phi_Extended2026D62.png" width="375"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V14/HGCal_l_vs_phi.png" width="375"/> <img class="PullRequest" src="HGCal_l_vs_phi_Extended2026D62.png" width="375"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V14/HGCal_x_vs_z_vs_Rsum.png" width="1000"/> <img class="PullRequest" src="HGCal_x_vs_z_vs_Rsum_Extended2026D62.png" width="1000"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V14/HGCal_l_vs_z_vs_Rsum.png" width="1000"/> <img class="PullRequest" src="HGCal_l_vs_z_vs_Rsum_Extended2026D62.png" width="1000"/> <br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V14/HGCal_x_vs_z_vs_Rloc.png" width="1000"/> <img class="PullRequest" src="HGCal_x_vs_z_vs_Rloc_Extended2026D62.png" width="1000"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V14/HGCal_l_vs_z_vs_Rloc.png" width="1000"/> <img class="PullRequest" src="HGCal_l_vs_z_vs_Rloc_Extended2026D62.png" width="1000"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V14/HGCal_x_vs_z_vs_Rloccos.png" width="1000"/> <img class="PullRequest" src="HGCal_x_vs_z_vs_Rloccos_Extended2026D62.png" width="1000"/><br/> <hr/> <img class="Reference" src="http://apsallid.web.cern.ch/apsallid/HGCalMaterial_V14/HGCal_l_vs_z_vs_Rloccos.png" width="1000"/> <img class="PullRequest" src="HGCal_l_vs_z_vs_Rloccos_Extended2026D62.png" width="1000"/><br/> <hr/> <hr/> </body></html>' > ${TEST_DIR}/index.html

if [[ ! -z ${JENKINS_UPLOAD_DIR} ]] ; then
   mkdir ${JENKINS_UPLOAD_DIR}/materialBudgetHGCalPlots
   cp  ${TEST_DIR}/Images/*.png ${JENKINS_UPLOAD_DIR}/materialBudgetHGCalPlots/
   cp  ${TEST_DIR}/index.html ${JENKINS_UPLOAD_DIR}/materialBudgetHGCalPlots/
   cp  ${TEST_DIR}/*.log ${JENKINS_UPLOAD_DIR}/materialBudgetHGCalPlots/ 
fi
