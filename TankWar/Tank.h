#include <QObject>
#include <QPainter>


typedef struct
{
	float x;
	float y;
	float r;
	float v;
	int score;
}SCircle;

typedef struct
{
	float x;
	float y;
	float w;
	float v;
	int score;
}SSquare;

typedef struct
{
	float x;
	float y;
	float w;
	float h;
	float v;
	int score;
}STriangle;

typedef struct
{
	float x;
	float y;
	float r;
	float v;
}SBullet;

class CTank : public QObject
{
public:
    void InitGame();                   //初始化游戏
    bool BlockHitTank();                //方块击中坦克
    void BulletHitBlock();             //子弹击中方块
    void DeleteBullet(int n);          //删除子弹
    void MoveBullet();                 //子弹运动
    void CreateBullet();               //生成子弹
    void MoveTank(int key);            //坦克运动

    void DeleteTriangle(int n);        //删除方块
    void DeleteSquare(int n);
    void DeleteCircle(int n);
    void DrawTriangle();               //画方块
    void DrawSquare();
    void DrawCircle();
    void MoveTriangle();               //方块运动
	void MoveSquare();
	void MoveCircle();
    void CreateTriangle();             //生成方块
	void CreateSquare();
	void CreateCircle();
    void MoveBlock();                  //方块运动
    void CreateBlock();                //生成方块
    void DrawBullet();
	void DrawTank();
	void DrawBackground();
    void Draw(QPainter * painter);
	CTank();
	virtual ~CTank();

    QPainter *pDC;

	//地图
    QPoint m_BK;
	int m_wBK, m_hBK;

	int m_Score;

	//坦克
    QPoint m_Center;  //坦克中心坐标
	int m_rCenter;
	int m_BodyLen;    //坦克边长
	int m_GunLen;     //炮管长度

	//子弹
	SBullet m_Bul[100];
	int m_nBul;

	//方块
	int m_nCir, m_nSqu, m_nTri;
	SCircle m_Cir[100];
	SSquare m_Squ[100];
	STriangle m_Tri[100];
};
