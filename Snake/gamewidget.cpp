#include "gamewidget.h"
#include "ui_gamewidget.h"


GameWidget::GameWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameWidget)
{
    ui->setupUi(this);

    m_timer = new QTimer;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(OnTimer()));

    connect(this, &GameWidget::SandGameOverMessage, this, [=](){
        if (m_snake.isGameOver())
        {
            m_over = new FormGameOver(m_snake.m_score);
            m_over->show();
            m_timer->stop();
        }
    });
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::paintEvent(QPaintEvent *event)
{
    m_painter.begin(this);

    DrawBackground();
    DrawFood();
    DrawSnake();

    m_painter.end();

    update();
}

void GameWidget::keyPressEvent(QKeyEvent *event)
{
    m_snake.setDirection(event->key());
}

void GameWidget::DrawBackground()
{
    //运动区域
    m_painter.drawRect(m_snake.m_map);

    //得分
    m_painter.setFont(QFont("Times New Roman", 30));
    m_painter.drawText(885, 450, "score");
    m_painter.drawText(910, 500, QString::number(m_snake.m_score));

}

void GameWidget::DrawSnake()
{
    int i;
    int x, y;

    for (i = 0; i < m_snake.m_len; i++)
    {
        if (i == 0)
        {
            if (m_snake.m_dir == UP)
                m_pix = QPixmap(":/res/upHead.png");
            if (m_snake.m_dir == DOWN)
                m_pix = QPixmap(":/res/downHead.png");
            if (m_snake.m_dir == RIGHT)
                m_pix = QPixmap(":/res/rightHead.png");
            if (m_snake.m_dir == LEFT)
                m_pix = QPixmap(":/res/leftHead.png");
        }
        else
        {
            m_pix = QPixmap(":/res/body.png");
        }
        x = m_snake.m_map.x() + m_snake.m_body[i].x() * m_snake.m_wBody;
        y = m_snake.m_map.y() + m_snake.m_body[i].y() * m_snake.m_wBody;
        m_painter.drawPixmap(x, y, m_pix.width(), m_pix.height(), m_pix);
    }
}

void GameWidget::DrawFood()
{
    int x, y;

    m_pix = QPixmap(":/res/food.png");

    x = m_snake.m_map.x() + m_snake.m_food.x() * m_snake.m_wBody;
    y = m_snake.m_map.y() + m_snake.m_food.y() * m_snake.m_wBody;
    m_painter.drawPixmap(x, y, m_pix.width(), m_pix.height(), m_pix);
}

void GameWidget::OnTimer()
{
    m_snake.Move();

    emit SandGameOverMessage();
}

void GameWidget::on_pushButton_start_clicked()
{
    m_timer->start(200);
}

void GameWidget::on_pushButton_stop_clicked()
{
    m_timer->stop();
}

void GameWidget::on_pushButton_restart_clicked()
{
    m_snake.initSnake();
    m_timer->stop();
}
