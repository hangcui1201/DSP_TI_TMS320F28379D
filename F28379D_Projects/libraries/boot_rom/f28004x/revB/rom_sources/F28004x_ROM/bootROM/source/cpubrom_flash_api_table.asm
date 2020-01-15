;;###########################################################################
;;
;; FILE:    rom_flash_api_table.asm
;;
;; TITLE:   Defines the FLash ROM API tables
;;
;;###########################################################################
;; $TI Release: F28004x Boot ROM V1.1 $
;; $Release Date: February 2017 $
;;###########################################################################


    .def    _rom_flash_ApiTable_start
    .def    __romApi_Fapi_getLibraryInfo
    .def    __romApi_Fapi_initializeAPI
    .def    __romApi_Fapi_setActiveFlashBank
    .def    __romApi_Fapi_issueAsyncCommandWithAddress
    .def    __romApi_Fapi_doBlankCheck
    .def    __romApi_Fapi_issueProgrammingCommand
    .def    __romApi_Fapi_issueProgrammingCommandForEccAddresses
    .def    __romApi_Fapi_doVerify
    .def    __romApi_Fapi_doVerifyBy16bits
    .def    __romApi_Fapi_issueAsyncCommand
    .def    __romApi_Fapi_issueFsmSuspendCommand
    .def    __romApi_Fapi_checkFsmForReady
    .def    __romApi_Fapi_getFsmStatus
    .def    __romApi_Fapi_calculateEcc
    .def    __romApi_Fapi_calculateFletcherChecksum
    .def    __romApi_Fapi_isAddressEcc
    .def    __romApi_Fapi_remapEccAddress
    .def    __romApi_Fapi_flushPipeline
    .def    __romApi_Fapi_calculatePsa
    .def    __romApi_Fapi_doPsaVerify
    .def    _rom_flash_ApiTable_end


    .ref    _Fapi_getLibraryInfo
    .ref    _Fapi_initializeAPI
    .ref    _Fapi_setActiveFlashBank
    .ref    _Fapi_issueAsyncCommandWithAddress
    .ref    _Fapi_doBlankCheck
    .ref    _Fapi_issueProgrammingCommand
    .ref    _Fapi_issueProgrammingCommandForEccAddresses
    .ref    _Fapi_doVerify
    .ref    _Fapi_doVerifyBy16bits
    .ref    _Fapi_issueAsyncCommand
    .ref    _Fapi_issueFsmSuspendCommand
    .ref    _Fapi_checkFsmForReady
    .ref    _Fapi_getFsmStatus
    .ref    _Fapi_calculateEcc
    .ref    _Fapi_calculateFletcherChecksum
    .ref    _Fapi_isAddressEcc
    .ref    _Fapi_remapEccAddress
    .ref    _Fapi_flushPipeline
    .ref    _Fapi_calculatePsa
    .ref    _Fapi_doPsaVerify


    .sect ".romFlashApiTable"
_rom_flash_ApiTable_start:
__romApi_Fapi_getLibraryInfo:
    LB _Fapi_getLibraryInfo
__romApi_Fapi_initializeAPI:
    LB _Fapi_initializeAPI
__romApi_Fapi_setActiveFlashBank:
    LB _Fapi_setActiveFlashBank
__romApi_Fapi_issueAsyncCommandWithAddress:
    LB _Fapi_issueAsyncCommandWithAddress
__romApi_Fapi_doBlankCheck:
    LB _Fapi_doBlankCheck
__romApi_Fapi_issueProgrammingCommand:
    LB _Fapi_issueProgrammingCommand
__romApi_Fapi_issueProgrammingCommandForEccAddresses:
    LB _Fapi_issueProgrammingCommandForEccAddresses
__romApi_Fapi_doVerify:
    LB _Fapi_doVerify
__romApi_Fapi_doVerifyBy16bits:
    LB _Fapi_doVerifyBy16bits
__romApi_Fapi_issueAsyncCommand:
    LB _Fapi_issueAsyncCommand
__romApi_Fapi_issueFsmSuspendCommand:
    LB _Fapi_issueFsmSuspendCommand
__romApi_Fapi_checkFsmForReady:
    LB _Fapi_checkFsmForReady
__romApi_Fapi_getFsmStatus:
    LB _Fapi_getFsmStatus
__romApi_Fapi_calculateEcc:
    LB _Fapi_calculateEcc
__romApi_Fapi_calculateFletcherChecksum:
    LB _Fapi_calculateFletcherChecksum
__romApi_Fapi_isAddressEcc:
    LB _Fapi_isAddressEcc
__romApi_Fapi_remapEccAddress:
    LB _Fapi_remapEccAddress
__romApi_Fapi_flushPipeline:
    LB _Fapi_flushPipeline
__romApi_Fapi_calculatePsa:
    LB _Fapi_calculatePsa
__romApi_Fapi_doPsaVerify:
    LB _Fapi_doPsaVerify
_rom_flash_ApiTable_end:


