#define NO_REPEAT 0
#define REPEAT    1

#define MEGA_MILLIONS   0x1
#define POWER_BALL      0x2
#define SUPER_LOTTO     0x3
#define FANTASY_5       0x4
#define DAILY_4         0x5
#define DAILY_3         0x6
#define CUSTOM          0xf

/* Mega Millions */
#define MM_WMIN   1
#define MM_WMAX  70
#define MM_WNUM   5
#define MM_WREP   NO_REPEAT
#define MM_RMIN   1
#define MM_RMAX  25
#define MM_RNUM   1
#define MM_RREP   NO_REPEAT
#define MM_QSTR   "Mega Millions"

/* Power Ball */
#define PB_WMIN   1
#define PB_WMAX  69
#define PB_WNUM   5
#define PB_WREP   NO_REPEAT
#define PB_RMIN   1
#define PB_RMAX  26
#define PB_RNUM   1
#define PB_RREP   NO_REPEAT
#define PB_QSTR   "Power Ball"

/* Super Lotto Plus */
#define SL_WMIN   1
#define SL_WMAX  47
#define SL_WNUM   5
#define SL_WREP   NO_REPEAT
#define SL_RMIN   1
#define SL_RMAX  27
#define SL_RNUM   1
#define SL_RREP   NO_REPEAT
#define SL_QSTR   "Super Lotto Plus"

/* Fantasy 5 */
#define F5_WMIN   1
#define F5_WMAX  39
#define F5_WNUM   5
#define F5_WREP   NO_REPEAT
#define F5_RNUM   0
#define F5_QSTR   "Fantasy 5"

/* Daily 4 */
#define D4_WMIN   0
#define D4_WMAX   9
#define D4_WNUM   4
#define D4_WREP   REPEAT
#define D4_RNUM   0
#define D4_QSTR   "Daily 4"

/* Daily 3 */
#define D3_WMIN   0
#define D3_WMAX   9
#define D3_WNUM   3
#define D3_WREP   REPEAT
#define D3_RNUM   0
#define D3_QSTR   "Daily 3"

/* CUSTOM */
#define CU_RNUM   0
#define CU_QSTR   "CUSTOM"

typedef unsigned char uchar;
typedef unsigned int  uint; 

struct lt_opts {
  uchar type;
  unsigned int iter;
};

struct lt_query {
  uchar wn_min;
  uchar wn_max;
  uchar t_wnum;
  uchar wn_rep;
  uchar rn_min;
  uchar rn_max;
  uchar t_rnum;
  uchar rn_rep;

  char query_str[32];
  uchar lt_type;
};

/* lt_args.c */
int lt_args(int argc, char **argv, struct lt_opts *opts);
void set_type(char *optarg, uchar *type);
void usage();

/* lt_drvr.c */
int lt_drvr(struct lt_query *q);
void lt_srand_init();
void lt_generator_loop(uchar num, uchar min, uchar max, uchar rep, uchar *LIST);

/* lt_init.c */
void lt_init(struct lt_query *q, uchar lt_type);
void lt_megamillions_init(struct lt_query *q);
void lt_powerball_init(struct lt_query *q);
void lt_superlotto_init(struct lt_query *q);
void lt_fantasy5_init(struct lt_query *q);
void lt_daily4_init(struct lt_query *q);
void lt_daily3_init(struct lt_query *q);
void lt_custom_init(struct lt_query *q);

/* lt_math.c */
int lt_factorial(uint total_num, uint draw_num, uint ad_num);

/* lt_grfx.c */

/* lt_prnt.c */
void print_odds(uchar type);
void print_megamillions_odds();
void print_powerball_odds();
void print_superlotto_odds();
void print_fantasy5_odds();
void print_daily4_odds();
void print_daily3_odds();
void print_custom_odds();
