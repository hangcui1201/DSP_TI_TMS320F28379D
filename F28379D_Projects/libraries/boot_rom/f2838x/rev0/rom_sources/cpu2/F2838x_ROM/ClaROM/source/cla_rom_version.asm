;;###########################################################################
;;
;; FILE:    cla_rom_version.asm
;;
;; TITLE:   CLA data ROM Version and checksum values.
;;
;; Functions:
;;
;;
;; Notes:
;;
;;###########################################################################
;; $TI Release: $
;; $Release Date:  $
;;###########################################################################

    .sect ".CROMVersion"
    .word 0x0100     ; CLA ROM Version v1.0
    .word 0x0318     ; Month/Year: (ex: 0x0318 = 3/18 = March 2018)

