#ifndef _COSTANTI_H_
#define _COSTANTI_H_
// ( varie dimensioni
#define KiB			1024UL
#define MiB			(1024*KiB)
#define GiB			(1024*MiB)
#define DIM_PAGINA		4096UL
#define DIM_BLOCK		512UL
// )

// ( limiti modificabili
// massimo numeri di semafori per livello
#define MAX_SEM			1024UL
// massimo numero di processi
#define MAX_PROC 		1024UL
// priorità minima dei processi esterni
#define MIN_EXT_PRIO		1024UL
// dimensione della memoria fisica
#define MEM_TOT			(128*MiB)
// dimensione dello heap utente
#define DIM_USR_HEAP		(1*MiB)
// dimensione degli stack utente
#define DIM_USR_STACK		(64*KiB)
// dimensione dello heap del modulo I/O
#define DIM_IO_HEAP		(1*MiB)
// dimensione degli stack sistema
#define DIM_SYS_STACK		(4*KiB)
// numero massimo di prd usati da dmaread/dmawrite
#define MAX_PRD			16
// indirizzo dal quale e' montato il kernel
#define KERNBASE 0x80000000L
// indirizzo in cui è caricato il descrittore del modulo utente
// caricato di default a metà della memoria fisica
#ifdef UBUNTU
    #define USER_MOD_START 0x84000000L
#else
    #define USER_MOD_START 0x83fff000L
#endif
// )

// ( tipi delle primitive
//   ( comuni
#define TIPO_A			0x00	// activate_p
#define TIPO_T			0x01	// terminate_p
#define TIPO_SI			0x02	// sem_ini
#define TIPO_W			0x03	// sem_wait
#define TIPO_S			0x04	// sem_signal
#define TIPO_D			0x05	// delay
#define TIPO_L			0x06	// do_log
#define TIPO_GMI		0x07	// getmeminfo (debug)
//   )
//   ( riservate per il modulo I/O
#define TIPO_APE		0x30	// activate_pe
#define TIPO_WFI		0x31	// wfi
#define TIPO_FG			0x32	// fill_gate
#define TIPO_AB			0x33	// abort_p
#define TIPO_IOP		0x34	// io_panic
#define TIPO_TRA		0x35	// trasforma
#define TIPO_ACC		0x36	// access
//   )
//   ( fornite dal modulo I/O
#define IO_TIPO_HDR		0x40	// readhd_n
#define IO_TIPO_HDW		0x41	// writehd_n
#define IO_TIPO_DMAHDR		0x42	// dmareadhd_n
#define IO_TIPO_DMAHDW		0x43	// dmawritehd_n
#define IO_TIPO_RCON		0x44	// readconsole
#define IO_TIPO_WCON		0x45	// writeconsole
#define IO_TIPO_INIC		0x46	// iniconsole
#define IO_TIPO_GMI		0x47	// getiomeminfo
//   )
// )

// ( suddivisione della memoria virtuale
//   N    = Numero di entrate in root_tab
//   I	  = Indice della prima entrata in root_tab
//   SIS  = SIStema
//   MIO  = Modulo IO
//   UTN  = modulo UTeNte
//   C    = Condiviso
//   P    = Privato
#define I_SIS_C		0
#define I_SIS_P		1
#define I_MIO_C		2
#define I_UTN_C       256
#define I_UTN_P	      384

#define N_SIS_C		1
#define N_SIS_P		1
#define N_MIO_C		1
#define N_UTN_C	      128
#define N_UTN_P	      128

// )


// ( costanti non modificabili
#define MIN_PROC_ID		0
#define MAX_PROC_ID		(MAX_PROC - 1)
#define MAX_PRIORITY		(MIN_EXT_PRIO - 1)
#define MIN_PRIORITY		0x1
#define MAX_EXT_PRIO		(MIN_EXT_PRIO + 0xFE)
#define LIV_UTENTE		    0
#define LIV_SISTEMA         1
#define LIV_MACCHINA        3
// )
#endif

// MACRO per gestione interruzioni
// Machine Status Register
#define MSTATUS_MPP_MASK (3L << 11) 
#define MSTATUS_MPP_M (3L << 11)
#define MSTATUS_MPP_S (1L << 11)
#define MSTATUS_MPP_U (0L << 11)
#define MSTATUS_MIE (1L << 3)   

// Supervisor Status Register
#define SSTATUS_SPP (1L << 8)   
#define SSTATUS_SPIE (1L << 5)   
#define SSTATUS_UPIE (1L << 4)   
#define SSTATUS_SIE (1L << 1)  
#define SSTATUS_UIE (1L << 0) 
