
// どーでもいい通知系

enum {
	SYS_UPDATECFG		= 0x0001,
	SYS_UPDATEOSCFG		= 0x0002,
	SYS_UPDATECLOCK		= 0x0004,
	SYS_UPDATERATE		= 0x0008,
	SYS_UPDATESBUF		= 0x0010,
	SYS_UPDATEMIDI		= 0x0020,
	SYS_UPDATESBOARD	= 0x0040,
	SYS_UPDATEFDD		= 0x0080,
	SYS_UPDATEHDD		= 0x0100,
	SYS_UPDATEMEMORY	= 0x0200,
	SYS_UPDATESERIAL1	= 0x0400
};


#ifdef __cplusplus
extern "C" {
#endif

void toolwin_fddaccess(BYTE drv);
void toolwin_hddaccess(BYTE drv);


extern	UINT	sys_updates;

#if 0
void sysmng_initialize(void);
void sysmng_update(UINT bitmap);
void sysmng_cpureset(void);
void sysmng_fddaccess(BYTE drv);
void sysmng_hddaccess(BYTE drv);
#else

// マクロ(単に関数コールしたくないだけ)
#define	sysmng_initialize()												\
			sys_updates = 0

#define	sysmng_update(a)												\
			sys_updates |= (a);											\
			if ((a) & SYS_UPDATEFDD) sysmng_updatecaption(1)

#define	sysmng_cpureset()												\
			sys_updates &= (SYS_UPDATECFG | SYS_UPDATEOSCFG);			\
			sysmng_workclockreset()

#define	sysmng_fddaccess(a)												\
			toolwin_fddaccess((a))

#define	sysmng_hddaccess(a)												\
			toolwin_hddaccess((a));

#endif


// ---- あとはOS依存部

void sysmng_workclockreset(void);
BOOL sysmng_workclockrenewal(void);
void sysmng_updatecaption(BYTE flag);

#ifdef __cplusplus
}
#endif

