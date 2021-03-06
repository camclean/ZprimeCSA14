import FWCore.ParameterSet.Config as cms

process = cms.Process("TTBSM")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )


process.source = cms.Source("PoolSource",
                                # replace 'myfile.root' with the source file you want to use
       fileNames = cms.untracked.vstring(
       #'dcap:///pnfs/cms/WAX/11/store/user/lpctlbsm/srappocc/TTJets_TuneZ2_7TeV-madgraph-tauola/ttbsm_v8_Summer11-PU_S4_START42_V11-v1/5c91b0700768331a44f51c8a9892d391/ttbsm_42x_mc_1_2_RlY.root'
       #'dcap:///pnfs/cms/WAX/11/store/user/lpctlbsm/weizou/WprimeToTBbar_M-2000_TuneZ2_7TeV-pythia6/ttbsm_v8_Summer11-PU_S4_-START42_V11-v1/2bcf344afee8f9cb5489a05cc32c05cf/ttbsm_42x_mc_1_1_J1v.root'
        #    '/store/results/B2G/TT_8TeV-mcatnlo/StoreResults-Summer12_DR53X-PU_S10_START53_V7A-v1_TLBSM_53x_v2-c04f3b4fa74c8266c913b71e0c74901d/TT_8TeV-mcatnlo/USER/StoreResults-Summer12_DR53X-PU_S10_START53_V7A-v1_TLBSM_53x_v2-c04f3b4fa74c8266c913b71e0c74901d/0000/FEBBE69C-1942-E211-9959-002354EF3BE2.root',
        #'/store/user/lpctlbsm/jdolen/TT_CT10_TuneZ2star_8TeV-powheg-tauola/Summer12_DR53X-PU_S10_START53_V7A-v2_TLBSM_53x_v3_bugfix_v1/99bd99199697666ff01397dad5652e9e/tlbsm_53x_v3_mc_1912_2_rsE.root'
        'file:/uscms_data/d3/camclean/CSA14/CMSSW_7_1_0_pre5/src/Analysis/processMiniAOD/test/RSGluonToTT_M-4000_13TeV_miniAODsample.root'
        )
                            )

process.ttbsmAna = cms.EDFilter('processMiniAOD',
                                AK8jetSrc_ = cms.InputTag('slimmedJetsAK8')
)
