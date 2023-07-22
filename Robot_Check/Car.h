#include <QPainter>


enum Move_Mode
{
	ShunYi, YunSu, ZhuanQuan, LuJing, FindXieLou
};

typedef struct
{
    int x, y;
}CPoint;

typedef struct
{
	float x, y;  //圆心坐标
	float r;     //转圈半径
	float omg;   //角速度
	float jd;    //初始角度和实时角度
	float Max;   //浓度最大值
	float Min;   //浓度最小值
	float Max_x, Max_y;  //浓度最大值坐标
	float Min_x, Min_y;  //浓度最小值坐标
}SCircleNDTest;

class CCar  
{
public:
	void initCircleNDTest();
	void DrawNDMaxMin();
	void MoveZhuanQuanChaZhaoXieLouDian();
	void MoveFindXieLouDian();
	int isOverLuJing();
	void DrawCar();
	void DrawLuJing();
	void ChuLiGuiJiZuoBiao(CPoint p);
	void MoveGuiJi();
	void ChuLiYuanXinCanShu();
	void ZhuanHuaMuBiaoDian(CPoint p);
	void MoveZhuanQuan();
	void MoveYunSuDaoMuBiaoDian();
	void Move();
	void MoveDianNaDaoNa();
    void Draw(QPainter *pDC);
	CCar();
	virtual ~CCar();

    QPainter *pDC;

	float m_kx;
	float m_ky;
	CPoint m_YD;

	float m_x, m_y;
	float m_v, m_vx, m_vy;
	float m_w;
	float m_MBx, m_MBy;
	float m_d;
	float m_YXx, m_YXy;   //转圈的圆心
	float m_JD;  
	float m_vJD;  //角速度
	int m_sn;     //顺时针为-1，逆时针为1
	float m_r;    //转圈半径
	float m_dir;  //圆心方向
	int m_mode;

	int m_nd;  //浓度

	float m_GJ[50][2];
	int m_nGJ;
	int m_bjCreate;
	int m_nowMB;

	float m_initJD;  //转圈初始角度
	int m_nd_max;    //转圈的最大浓度
	float m_x_max;
	float m_y_max;   //转圈的最大浓度坐标

	SCircleNDTest m_ndCir;
};

