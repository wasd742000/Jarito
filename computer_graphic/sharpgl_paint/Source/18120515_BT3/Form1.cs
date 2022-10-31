using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System.Diagnostics;


namespace SharpGL
{
    // Cac doi tuong 2D 
    public enum DRAWING_MODE
    {
        LINE,
        CIRCLE,
        RECTANGLE,
        ELLIPSE,
        EQUIL_TRIANGLE,
        PENTAGON,
        HEXAGON,
        POLYGON,
        FLOOD_FILL
    }

    // Che do ve & chon control points
    public enum TOOLS_MODE
    {
        DRAWING,
        SELECT_CTRLPOINT,
        TRANSLATE,
        ROTATE
    }

    // myRaster de luu cac list cac control points
    public struct myRaster
    {
        public List<Point> controlPoints;
        public Color rasterColor;
        public DRAWING_MODE raster_toolMode;
        public int rasterSize;

        public myRaster(Color _color, DRAWING_MODE _raster_toolMode, int size)
        {
            controlPoints = new List<Point>();
            rasterColor = _color;
            raster_toolMode = _raster_toolMode;
            rasterSize = size;
        }
        public myRaster(List<Point> lst, Color _color, DRAWING_MODE _raster_toolMode, int size)
        {
            controlPoints = new List<Point>();
            controlPoints.AddRange(lst);
            rasterColor = _color;
            raster_toolMode = _raster_toolMode;
            rasterSize = size;
        }
        public myRaster(myRaster other)
        {
            controlPoints = new List<Point>(other.controlPoints);
            rasterColor = other.rasterColor;
            raster_toolMode = other.raster_toolMode;
            rasterSize = other.rasterSize;
        }
        public void isNull(out bool flag)
        {
            if (controlPoints == null)
                flag = true;
            else
                flag = false;
        }

    }

    public partial class Lab3_Form : Form
    {
        Point begPoint, endPoint, midPoint; // diem dau, cuoi, giua
        Point tmpStart, tmpEnd;
        int curSize; // Kich co ve hien tai
        TOOLS_MODE curTool = SharpGL.TOOLS_MODE.DRAWING; // Mac dinh drawing
        Color curColor; // Bien mau de ve hinh
        DRAWING_MODE curShape; // Doi tuong 2D
        List<myRaster> curRaster = new List<myRaster>(); // Luu cac doi tuong da ve

        bool isMouseDown; // Bien kiem soat con tro chuot co dang duoc giu khong
                          // KT khi thay doi color/size trong che do select control points
        bool select_changeColor = false;
        bool select_changeSize = false;
        bool isMouse_rightClick = false; // kt click chuot phai
        bool isAffineTrans = false;
        bool isSelected = false; // Kiem tra da chon object
        int tmpObject = -1; // Luu tam vi tri object trong list

        public Lab3_Form()
        {
            InitializeComponent();
            // Mac dinh
            curColor = Color.Black;
            curShape = DRAWING_MODE.LINE;
            comboBox_ChangeSize.SelectedIndex = 0; // Net ve size = 1
            comboBox_changeMode.SelectedItem = "Draw";
            begPoint = new Point(-1, -1);
        }

        // Ham khoi tao cho opengl
        private void openGLControl_OpenGLInitialized(object sender, EventArgs e)
        {
            // get the openGL object
            OpenGL gl = openGLControl.OpenGL;
            // mau nen 
            gl.ClearColor(255, 255, 255, 0);
            // set the projection matrix
            gl.MatrixMode(OpenGL.GL_PROJECTION);
            // load the identify
            gl.LoadIdentity();
        }

        //_____________________________________________XU LY MOUSE EVENTS___________________________________

        #region CAC HAM XU LY MOUSE EVENTS
        // User chon doan thang
        private void bt_Line_Click(object sender, EventArgs e)
        {
            comboBox_changeMode.Text = "Draw";
            curTool = SharpGL.TOOLS_MODE.DRAWING;

            curShape = DRAWING_MODE.LINE; // Nguoi dung chon ve duong thang
            isMouseDown = false;
        }

        // User chon hinh chu nhat
        private void bt_Rectangle_Click(object sender, EventArgs e)
        {
            curTool = SharpGL.TOOLS_MODE.DRAWING;
            comboBox_changeMode.Text = "Draw";
            curShape = DRAWING_MODE.RECTANGLE;
            isMouseDown = false;
        }

        // User chon tam giac deu
        private void bt_Triangle_Click(object sender, EventArgs e)
        {
            curTool = SharpGL.TOOLS_MODE.DRAWING;
            comboBox_changeMode.Text = "Draw";
            curShape = DRAWING_MODE.EQUIL_TRIANGLE;
            isMouseDown = false;

        }
        // User chone ngu giac deu
        private void bt_Pentagon_Click(object sender, EventArgs e)
        {

            curTool = SharpGL.TOOLS_MODE.DRAWING;
            comboBox_changeMode.Text = "Draw";
            curShape = DRAWING_MODE.PENTAGON;
            isMouseDown = false;
        }

        // User chon luc giac deu
        private void bt_Hexagon_Click(object sender, EventArgs e)
        {

            curTool = SharpGL.TOOLS_MODE.DRAWING;
            comboBox_changeMode.Text = "Draw";
            curShape = DRAWING_MODE.HEXAGON;
            isMouseDown = false;
        }

        // User chon duong tron
        private void bt_Circle_Click(object sender, EventArgs e)
        {

            curTool = SharpGL.TOOLS_MODE.DRAWING;
            comboBox_changeMode.Text = "Draw";
            curShape = DRAWING_MODE.CIRCLE;
            isMouseDown = false;
        }

        // User chon ellipse
        private void bt_Ellipse_Click(object sender, EventArgs e)
        {
            curTool = SharpGL.TOOLS_MODE.DRAWING;
            comboBox_changeMode.Text = "Draw";
            curShape = DRAWING_MODE.ELLIPSE;
            isMouseDown = false;
        }

        //User chon da giac
        private void bt_Polygon_Click(object sender, EventArgs e)
        {
            curTool = SharpGL.TOOLS_MODE.DRAWING;
            comboBox_changeMode.Text = "Draw";
            curShape = DRAWING_MODE.POLYGON;
            isMouseDown = false;
        }

        // User chon to loang
        private void bt_Flood_Fill_Click(object sender, EventArgs e)
        {
            curShape = DRAWING_MODE.FLOOD_FILL;
        }

        // Chuyen che do
        private void comboBox_changeMode_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBox_changeMode.Text == "Draw")
                curTool = SharpGL.TOOLS_MODE.DRAWING;
            if (comboBox_changeMode.Text == "Select object")
                curTool = SharpGL.TOOLS_MODE.SELECT_CTRLPOINT;
            else if (comboBox_changeMode.Text == "Translate")
                curTool = SharpGL.TOOLS_MODE.TRANSLATE;
            else if (comboBox_changeMode.Text == "Rotate")
                curTool = SharpGL.TOOLS_MODE.ROTATE;
        }

        // User chon doi mau
        private void bt_ColorTable_Click(object sender, EventArgs e)
        {
            // Goi hop thoai chon mau
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                bt_CurrentColor.BackColor = colorDialog1.Color;
                curColor = colorDialog1.Color; // Luu lai mau user chon

                // Xu ly rieng cho khi user chon diem dieu khien
                if (curTool == SharpGL.TOOLS_MODE.SELECT_CTRLPOINT)
                {
                    select_changeColor = true;
                }
            }
        }

        // User chon doi size net ve
        private void comboBox_changeSize_click(object sender, EventArgs e)
        {
            curSize = int.Parse(comboBox_ChangeSize.Text);
            if (curTool == SharpGL.TOOLS_MODE.SELECT_CTRLPOINT)
                select_changeSize = true;
        }


        // Tinh lai diem dau/cuoi cho cac hinh ve theo pp noi tiep hinh vuong, bien thien deu (circle, equil_triangle, pentagon, hexagon)
        private void recalculate_begPoint_and_endPoint(DRAWING_MODE sh)
        {
            if (curShape == DRAWING_MODE.CIRCLE || curShape == DRAWING_MODE.EQUIL_TRIANGLE || curShape == DRAWING_MODE.PENTAGON || curShape == DRAWING_MODE.HEXAGON)
            {

                int difX = Math.Abs(endPoint.X - begPoint.X);

                // Tinh deltaX va deltaY
                int dx = endPoint.X - begPoint.X;
                int dy = endPoint.Y - begPoint.Y;

                // TH1: x, y cung tang
                // TH2: x tang, y giam
                // TH3: x giam, y tang
                // TH4: x giam, y giam
                if (dx > 0 && dy > 0)
                    endPoint = new Point(begPoint.X + difX, begPoint.Y + difX);
                else if (dx > 0 && dy <= 0)
                    endPoint = new Point(begPoint.X + difX, begPoint.Y - difX);
                else if (dx <= 0 && dy > 0)
                    endPoint = new Point(begPoint.X - difX, begPoint.Y + difX);
                else
                    endPoint = new Point(begPoint.X - difX, begPoint.Y - difX);
            }
        }

        // Cap nhat diem cuoi khi nguoi dung dang keo chuot
        private void ctrl_OpenGLControl_MouseMove(object sender, MouseEventArgs e)
        {
            // Cap nhat diem endPoint
            if (isMouseDown)
            {
                if (curTool == SharpGL.TOOLS_MODE.DRAWING)
                {
                    // Cap nhat diem cuoi
                    endPoint = new Point(e.Location.X, e.Location.Y);
                    // Tinh lai endPoint neu curShape la Circle, Triangle, Pentagon, Hexagon
                    recalculate_begPoint_and_endPoint(curShape);
                }
                else
                {
                    // Cập nhật tmpEnd
                    tmpEnd = new Point(e.Location.X, e.Location.Y);
                }
            }

        }

        // Cap nhat toa do diem cuoi khi nguoi dung buong chuot ra
        private void ctrl_OpenGLControl_MouseUp(object sender, MouseEventArgs e)
        {
            if (curTool != SharpGL.TOOLS_MODE.DRAWING)
            {
                if (curTool != SharpGL.TOOLS_MODE.SELECT_CTRLPOINT)
                {
                    tmpEnd = new Point(e.X, e.Y);
                    isMouseDown = false;
                    // Co the select lai 1 object khac
                    isSelected = false;
                }
                if (curTool == SharpGL.TOOLS_MODE.TRANSLATE)
                {
                    // Tinh khoang doi trx va try
                    int xSpan = tmpEnd.X - tmpStart.X;
                    int ySpan = tmpEnd.Y - tmpStart.Y;
                    List<Point> lst = new List<Point>();

                    begPoint = new Point(begPoint.X + xSpan, begPoint.Y + ySpan);
                    endPoint = new Point(endPoint.X + xSpan, endPoint.Y + ySpan);
                    lst.Add(begPoint);
                    lst.Add(endPoint);
                    // Thuc hien lui doi tuong da ve vao List<MyBitMap> raster
                    myRaster tmp = new myRaster(curColor, curShape, curSize);
                    tmp.controlPoints.Add(begPoint);
                    tmp.controlPoints.Add(endPoint);
                    // Them tmp vao raster
                    curRaster.Add(tmp);

                    // Khi nguoi dung vua ve xong hinh thi ve control points
                    drawCtrlPoints(lst, curShape);

                }
                else if (curTool == SharpGL.TOOLS_MODE.ROTATE)
                {
                    Point CenterRotate = new Point((begPoint.X + endPoint.X) / 2, (begPoint.Y + endPoint.Y) / 2);
                    double rotateAngle = 0;

                    // Tọa độ 2 vector
                    int[] vector1 = { 0, 1 };
                    int[] vector2 = { tmpEnd.X - CenterRotate.X, -tmpEnd.Y + CenterRotate.Y };

                    // Độ dài của 2 vector
                    double length_vector1 = Math.Sqrt(Math.Pow(vector1[0], 2) + Math.Pow(vector1[1], 2));
                    double length_vector2 = Math.Sqrt(Math.Pow(vector2[0], 2) + Math.Pow(vector2[1], 2));

                    // Xác định tử và mẫu
                    int num = vector1[0] * vector2[0] + vector1[1] * vector2[1];
                    double deno = length_vector1 * length_vector2;
                    rotateAngle = Math.Acos(num / deno) * 180 / Math.PI;

                    if (tmpEnd.X < CenterRotate.X)
                        rotateAngle += 90;

                    double r = rotateAngle * Math.PI / 180;
                    // Toa do sau khi xoay cua begPoint va endPoint
                    int pSRx = (int)(Math.Cos(r) * begPoint.X - Math.Sin(r) * begPoint.Y);
                    int pSRy = (int)(Math.Cos(r) * begPoint.Y + Math.Sin(r) * begPoint.X);
                    int pERx = (int)(Math.Cos(r) * endPoint.X - Math.Sin(r) * endPoint.Y);
                    int pERy = (int)(Math.Cos(r) * endPoint.X + Math.Sin(r) * endPoint.Y);

                    begPoint = new Point(pSRx, pSRy);
                    endPoint = new Point(pERx, pERy);

                    List<Point> lst = new List<Point>();
                    lst.Add(begPoint);
                    lst.Add(endPoint);

                    // Ve lai control points
                    drawCtrlPoints(lst, curShape);

                    myRaster tmp = new myRaster(curColor, curShape, curSize);
                    tmp.controlPoints.Add(begPoint);
                    tmp.controlPoints.Add(endPoint);
                    // Them tmp vao raster
                    curRaster.Add(tmp);
                }
                // reset lai toa do
                begPoint = new Point(-1, -1);
                endPoint = new Point(-1, -1);
            }
            else
            {
                // Neu nguoi dung khong ve da giac thi ket thuc viec ve hinh
                if (curShape != DRAWING_MODE.POLYGON)
                {
                    openGLControl.Cursor = Cursors.Default; // Tra ve con tro chuot nhu cu
                    isMouseDown = false; // chuot het di chuyen

                    // Thuc hien lui doi tuong da ve vao List<myRaster> curRaster
                    myRaster tmp = new myRaster(curColor, curShape, curSize);
                    if (curShape == DRAWING_MODE.FLOOD_FILL)
                    { // Neu to mau thi chi can luu diem dau tien click vao
                        tmp.controlPoints.Add(begPoint);
                    }
                    else // Con ve thi luu 2 diem
                    {
                        tmp.controlPoints.Add(begPoint);
                        tmp.controlPoints.Add(endPoint);

                        drawCtrlPoints(tmp.controlPoints, curShape);
                    }

                    // Them tmp vao curRaster
                    curRaster.Add(tmp);

                    // reset lai toa do
                    begPoint = new Point(-1, -1);
                    endPoint = new Point(-1, -1);
                }

            }
        }

        // Xu ly su kien nguoi dung click chuot
        private void openGLControl_MouseClick(object sender, MouseEventArgs e)
        {
            // Neu nguoi dung nhap chuot phai va ket thuc ve da giac
            if (e.Button == MouseButtons.Right && curShape == DRAWING_MODE.POLYGON)
            {
                isMouse_rightClick = true; // Danh dau da click chuot phai
                curRaster[curRaster.Count - 1].controlPoints.Add(begPoint);

            }
        }

        // Cap nhat point khi mouse down
        private void ctrl_OpenGLControl_MouseDown(object sender, MouseEventArgs e)
        {
            if (curTool == SharpGL.TOOLS_MODE.DRAWING) // Che do drawing
            {
                if (curShape != DRAWING_MODE.POLYGON)
                {
                    // Cap nhat toa do diem dau
                    begPoint = new Point(e.Location.X, e.Location.Y);
                    endPoint = new Point(e.X, e.Y); // Mac dinh endPoint = begPoint
                }
                else // xu ly cho hinh da giac
                {
                    // Bat dau click
                    if (begPoint.X == -1)
                    {
                        begPoint = new Point(e.X, e.Y);
                        endPoint = new Point(e.X, e.Y); // Mac dinh endPoint = begPoint
                        midPoint = new Point(e.X, e.Y); // Mac dinh midPoint = begPoint

                        // click ve da giac dau tien
                        myRaster tmp = new myRaster(curColor, curShape, curSize);
                        tmp.controlPoints.Add(begPoint);
                        // luu tmp vao curRaster
                        curRaster.Add(tmp);
                    }
                    else
                    {
                        midPoint = new Point(endPoint.X, endPoint.Y);
                        endPoint = new Point(e.X, e.Y);

                        // Luu points da giac moi lan user click chuot
                        curRaster[curRaster.Count - 1].controlPoints.Add(e.Location);
                    }

                }
            }
            else
            {
                tmpStart = tmpEnd = new Point(e.X, e.Y);
            }

            openGLControl.Cursor = Cursors.Cross;
            isMouseDown = true; // Chuot dang bat dau di chuyen
        }

        // Cac ham chu thich tools
        private void bt_Line_MouseHover(object sender, EventArgs e)
        {
            toolTip1.SetToolTip(bt_Line, "Đoạn thẳng");
        }
        private void bt_Triangle_MouseHover(object sender, EventArgs e)
        {
            toolTip1.SetToolTip(bt_Triangle, "Tam giác đều");
        }
        private void bt_Rectangle_MouseHover(object sender, EventArgs e)
        {
            toolTip1.SetToolTip(bt_Rectangle, "Hình chữ nhật");
        }
        private void bt_Pentagon_MouseHover(object sender, EventArgs e)
        {
            toolTip1.SetToolTip(bt_Pentagon, "Hình ngũ giác đều");
        }
        private void bt_Hexagon_MouseHover(object sender, EventArgs e)
        {
            toolTip1.SetToolTip(bt_Hexagon, "Hình lục giác đều");
        }
        private void bt_Polygon_MouseHover(object sender, EventArgs e)
        {
            toolTip1.SetToolTip(bt_Polygon, "Hình đa giác");
        }

        private void bt_Circle_MouseHover(object sender, EventArgs e)
        {
            toolTip1.SetToolTip(bt_Circle, "Hình tròn");
        }
        private void bt_Ellipse_MouseHover(object sender, EventArgs e)
        {
            toolTip1.SetToolTip(bt_Ellipse, "Hình Ellipse");
        }
        private void openGLControl_MouseHover(object sender, EventArgs e)
        {
            toolTip1.SetToolTip(openGLControl, "Vẽ ở vùng này");
        }
        #endregion

        //_________________________________________CAC HAM VE_________________________________________
        #region CAC HAM VE DOI TUONG 2D

        // Ve mot pixel
        private void drawPixel(OpenGL gl, Point p)
        {
            if (p.X <= gl.RenderContextProvider.Width && p.Y <= gl.RenderContextProvider.Height)
            {
                gl.Enable(OpenGL.GL_POINT_SMOOTH);
                gl.PointSize(curSize);
                gl.Begin(OpenGL.GL_POINTS);
                gl.Vertex(p.X, gl.RenderContextProvider.Height - p.Y); //Set pixel coordinates 
                gl.End();
                gl.Flush();
                gl.Disable(OpenGL.GL_POINT_SMOOTH);
            }
        }

        // Ve doan thang thuat toan Bresenham moi truong hop
        private void drawLine(OpenGL gl, Point p1, Point p2)
        {

            Point tmp_p = new Point();
            int dx, dy, abs_dx, abs_dy, px, py, xe, ye, i;


            dx = p2.X - p1.X;
            dy = p2.Y - p1.Y;
            abs_dx = Math.Abs(dx);
            abs_dy = Math.Abs(dy);
            px = 2 * abs_dy - abs_dx;
            py = 2 * abs_dx - abs_dy;

            // Truong hop |slope| < 1 
            if (abs_dy < abs_dx)
            {
                if (dx >= 0)
                {
                    tmp_p.X = p1.X;
                    tmp_p.Y = p1.Y;
                    xe = p2.X;
                }
                else
                {
                    tmp_p.X = p2.X;
                    tmp_p.Y = p2.Y;
                    xe = p1.X;
                }
                drawPixel(gl, tmp_p);
                for (i = 0; tmp_p.X < xe; i++)
                {
                    tmp_p.X += 1;
                    if (px < 0)
                    {
                        px = px + 2 * abs_dy;
                    }
                    else
                    {
                        if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                        {
                            tmp_p.Y += 1;
                        }
                        else
                        {
                            tmp_p.Y -= 1;
                        }
                        px = px + 2 * (abs_dy - abs_dx);
                    }
                    drawPixel(gl, tmp_p);
                }
            }
            // Truong hop |slope| >= 1
            else
            {
                if (dy >= 0)
                {
                    tmp_p.X = p1.X;
                    tmp_p.Y = p1.Y;
                    ye = p2.Y;
                }
                else
                {
                    tmp_p.X = p2.X;
                    tmp_p.Y = p2.Y;
                    ye = p1.Y;
                }
                drawPixel(gl, tmp_p);
                for (i = 0; tmp_p.Y < ye; i++)
                {
                    tmp_p.Y += 1;
                    if (py <= 0)
                    {
                        py = py + 2 * abs_dx;
                    }
                    else
                    {
                        if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                        {
                            tmp_p.X += 1;
                        }
                        else
                        {
                            tmp_p.X -= 1;
                        }
                        py = py + 2 * (abs_dx - abs_dy);
                    }
                    drawPixel(gl, tmp_p);
                }
            }
        }

        // Ve hinh chu nhat
        private void drawRec(OpenGL gl, Point p1, Point p2)
        {
            Point tmp1 = new Point(p1.X, p2.Y), tmp2 = new Point(p2.X, p1.Y);
            // Ve 4 canh
            drawLine(gl, p1, tmp2);
            drawLine(gl, tmp2, p2);
            drawLine(gl, p2, tmp1);
            drawLine(gl, tmp1, p1);
        }

        // Tinh khoang cach giua 2 diem
        private void getDistance(Point a, Point b, out double d)
        {
            d = Math.Sqrt(Math.Pow(a.X - b.X, 2) + Math.Pow(a.Y - b.Y, 2));
        }

        private void getDistance(int xa, int ya, int xb, int yb, out double d)
        {
            d = Math.Sqrt(Math.Pow(xa - xb, 2) + Math.Pow(ya - yb, 2));
        }

        // Bo tro ve duong tron: ve 8 diem doi xung trong duong tron
        private void put8Pixel(OpenGL gl, int a, int b, int x, int y)
        {
            gl.PointSize(curSize + 1);
            gl.Begin(OpenGL.GL_POINTS);
            gl.Vertex(a + x, b + y);
            gl.Vertex(a + x, b - y);
            gl.Vertex(a - x, b + y);
            gl.Vertex(a - x, b - y);
            gl.Vertex(a + y, b + x);
            gl.Vertex(a - y, b + x);
            gl.Vertex(a + y, b - x);
            gl.Vertex(a - y, b - x);
            gl.End();
            gl.Flush();
        }

        // Ve hinh tron pp midPoint
        private void drawCircle(OpenGL gl, Point p1, Point p2)
        {
            // Tinh lai toa do y cua begPoint, endPoint
            Point _p1, _p2;
            _p1 = new Point(p1.X, gl.RenderContextProvider.Height - p1.Y);
            _p2 = new Point(p2.X, gl.RenderContextProvider.Height - p2.Y);

            // Ban kinh la cung chinh la canh cua hinh vuong ngoai tiep hinh tron
            double r;
            getDistance(_p1, _p2, out r);
            r = r / (2 * Math.Sqrt(2));

            int xc = (_p1.X + _p2.X) / 2;
            int yc = (_p1.Y + _p2.Y) / 2;

            int x = 0;
            int y = (int)r;
            int p = (int)(5 / 4 - r);

            // Ve diem  dau (0, r)
            put8Pixel(gl, xc, yc, x, y);

            while (x < y)
            {
                x++;
                if (p < 0)
                    p += 2 * x + 3;
                else
                {
                    y--;
                    p += 2 * (x - y) + 5;
                }
                put8Pixel(gl, xc, yc, x, y);
            }
        }

        // Bo tro ve ellipse: ve 4 diem doi xung trong ellipse 
        private void put4Pixel(OpenGL gl, int a, int b, int x, int y)
        {
            gl.PointSize(curSize + 1);
            gl.Begin(OpenGL.GL_POINTS);
            gl.Vertex(a + x, b + y);
            gl.Vertex(a + x, b - y);
            gl.Vertex(a - x, b - y);
            gl.Vertex(a - x, b + y);
            gl.End();
            gl.Flush();
        }

        // Ve ellipse pp midpoint
        private void drawEllipse(OpenGL gl, Point p1, Point p2)
        {
            Point _p1 = new Point(p1.X, gl.RenderContextProvider.Height - p1.Y);
            Point _p2 = new Point(p2.X, gl.RenderContextProvider.Height - p2.Y);
            // Tinh tam C(xc, yc) cua ellipse
            int xc = (int)((_p1.X + _p2.X) / 2);
            int yc = (int)((_p1.Y + _p2.Y) / 2);

            // Goi A(xa, ya) la giao diem cua 0x va ellipse
            int xa = _p2.X;
            int ya = (int)((_p1.Y + _p2.Y) / 2);

            // Goi B(xb, yb) la giao diem cua 0y va ellipse
            int xb = (int)((_p1.X + _p2.X) / 2);
            int yb = _p1.Y;

            // Tinh rx va ry
            double rx;
            getDistance(xa, ya, xc, yc, out rx);
            double ry;
            getDistance(xb, yb, xc, yc, out ry);

            // Diem dau
            int x = 0;
            int y = (int)ry;

            double ry2 = ry * ry; // ry^2
            double rx2 = rx * rx; // rx^2

            double p = ry2 - rx2 * ry + (1 / 4) * rx2;
            double A = 2 * ry2 * x;
            double B = 2 * rx2 * y;

            // Ve 4 diem dau tien
            put4Pixel(gl, xc, yc, x, y);
            // Truong hop: 0 < |dy/dx| <= 1
            while (A < B)
            {
                x++;
                if (p < 0)
                {
                    A += 2 * ry2;
                    p += A + ry2;
                }
                else
                {
                    y--;
                    A += 2 * ry2;
                    B -= 2 * rx2;
                    p += A - B + ry2;
                }
                put4Pixel(gl, xc, yc, x, y);
            }

            // Truong hop: |dy/dx| > 1
            float xlast = x, ylast = y;
            A = 2 * ry2 * xlast;
            B = 2 * rx2 * ylast;
            p = ry2 * Math.Pow((xlast + 1 / 2), 2) + rx2 * Math.Pow((ylast - 1), 2) - rx2 * ry2;

            while (y != 0)
            {
                y--;
                if (p < 0)
                {
                    x++;
                    A += 2 * ry2;
                    B -= 2 * rx2;
                    p += A - B + rx2;
                }
                else
                {
                    B -= 2 * rx2;
                    p += -B + rx2;
                }
                put4Pixel(gl, xc, yc, x, y);
            }

        }

        // Ve tam giac pp quay diem
        private void drawTriangle(OpenGL gl, Point p1, Point p2)
        {

            // Tinh lai toa do y cua p1, p2
            Point _p1, _p2;
            _p1 = new Point(p1.X, gl.RenderContextProvider.Height - p1.Y);
            _p2 = new Point(p2.X, gl.RenderContextProvider.Height - p2.Y);

            // Ban kinh la cung chinh la canh cua hinh vuong ngoai tiep tam giac deu
            double r;
            getDistance(_p1, _p2, out r);
            r = r / (2 * Math.Sqrt(2));

            int xc = (_p1.X + _p2.X) / 2;
            int yc = (_p1.Y + _p2.Y) / 2;

            int x = 0;
            int y = (int)r;

            const int totalSegments = 3;
            // Bat dau ve
            gl.Enable(OpenGL.GL_LINE_SMOOTH);
            gl.Begin(OpenGL.GL_LINE_LOOP);

            for (int alpha = 0; alpha < 360; alpha += 360 / totalSegments)
            {
                double alpha_rad = alpha * Math.PI / 180;
                // Tinh x, y
                gl.Vertex(xc + x * Math.Cos(alpha_rad) - y * Math.Sin(alpha_rad)
                    , yc + x * Math.Sin(alpha_rad) + y * Math.Cos(alpha_rad));
            }

            gl.End();
            gl.Flush();
            gl.Disable(OpenGL.GL_LINE_SMOOTH);
        }


        // Ve ngu giac deu pp quay diem
        private void drawPentagon(OpenGL gl, Point p1, Point p2)
        {
            // Tinh lai toa do y cua p1, p2
            Point _p1, _p2;
            _p1 = new Point(p1.X, gl.RenderContextProvider.Height - p1.Y);
            _p2 = new Point(p2.X, gl.RenderContextProvider.Height - p2.Y);

            // Ban kinh la cung chinh la canh cua hinh vuong ngoai tiep ngu giac deu
            double r;
            getDistance(_p1, _p2, out r);
            r = r / (2 * Math.Sqrt(2));

            // Tam duong tron tai trung diem cua doan thang noi _p1 va _p2
            int xc = (_p1.X + _p2.X) / 2;
            int yc = (_p1.Y + _p2.Y) / 2;

            int x = 0;
            int y = (int)r;

            const int totalSegments = 5;
            // Bat dau ve
            gl.Enable(OpenGL.GL_LINE_SMOOTH);
            gl.Begin(OpenGL.GL_LINE_LOOP);

            for (int alpha = 0; alpha < 360; alpha += 360 / totalSegments)
            {
                double alpha_rad = alpha * Math.PI / 180;
                gl.Vertex(xc + x * Math.Cos(alpha_rad) - y * Math.Sin(alpha_rad)
                    , yc + x * Math.Sin(alpha_rad) + y * Math.Cos(alpha_rad));
            }

            gl.End();
            gl.Flush();
            gl.Disable(OpenGL.GL_LINE_SMOOTH);
        }
        // Ham ve luc giac deu pp quay diem
        private void drawHexagon(OpenGL gl, Point p1, Point p2)
        {
            Point _p1, _p2;
            _p1 = new Point(p1.X, gl.RenderContextProvider.Height - p1.Y);
            _p2 = new Point(p2.X, gl.RenderContextProvider.Height - p2.Y);

            // Ban kinh la cung chinh la canh cua hinh vuong ngoai tiep luc giac deu
            double r;
            getDistance(_p1, _p2, out r);
            r = r / (2 * Math.Sqrt(2));

            int xc = (_p1.X + _p2.X) / 2;
            int yc = (_p1.Y + _p2.Y) / 2;

            int x = 0;
            int y = (int)r;

            const int totalSegments = 6;
            // Bat dau ve
            gl.Enable(OpenGL.GL_LINE_SMOOTH);
            gl.Begin(OpenGL.GL_LINE_LOOP);

            for (int alpha = 0; alpha < 360; alpha += 360 / totalSegments)
            {
                double alpha_rad = alpha * Math.PI / 180;
                gl.Vertex(xc + x * Math.Cos(alpha_rad) - y * Math.Sin(alpha_rad)
                    , yc + x * Math.Sin(alpha_rad) + y * Math.Cos(alpha_rad));
            }

            gl.End();
            gl.Flush();
            gl.Disable(OpenGL.GL_LINE_SMOOTH);
        }

        // Ve da giac bat ky
        private void drawPolygon(OpenGL gl)
        {
            // Connect begPoint vs endPoint neu mouse right click
            if (isMouse_rightClick)
            {
                drawLine(gl, endPoint, begPoint);
                isMouseDown = false; // Ket thuc ve da giac
                isMouse_rightClick = false; // reset rightclick flag

                // Ve xong da giac thi ve controlpoints
                drawCtrlPoints(curRaster[curRaster.Count - 1].controlPoints, curShape);

                // reset lai cac toa do
                begPoint = new Point(-1, -1);
                endPoint = new Point(-1, -1);
                midPoint = new Point(-1, -1);

            }
            else // Tiep tuc ve da giac khi chua ket thuc
                drawLine(gl, midPoint, endPoint);
        }
        // Ve da giac tu List<Point>
        private void drawPolygon(OpenGL gl, List<Point> lstPoints)
        {
            if (lstPoints.Count > 1)
            {
                if (curTool == SharpGL.TOOLS_MODE.DRAWING)
                {
                    for (int i = 0; i < lstPoints.Count - 1; i++)
                    {
                        drawLine(gl, lstPoints[i], lstPoints[i + 1]);
                    }
                }

            }
        }

        #endregion

        //____________________________________SELECT CONTROL POINTS____________________________________
        #region XU LY CONTROL POINTS
        // Ve control points tu List cac control points
        private void drawCtrlPoints(List<Point> lst, DRAWING_MODE sh)
        {
            // get the OpenGL object
            OpenGL gl = openGLControl.OpenGL;
            // Chon mau de ve control points. Chon mau Light grey
            gl.Color(Color.Red.R / 255.0, 0, 0, 0);

            // Tim cac control points cua doi tuong nay
            List<Point> controlPoints;

            calCtrlPoints(lst, sh, out controlPoints);
            foreach (var p in controlPoints)
            {
                gl.PointSize(8);
                gl.Begin(OpenGL.GL_POINTS);
                gl.Vertex(p.X, gl.RenderContextProvider.Height - p.Y);
                gl.End();
                gl.Flush();
            }
        }

        // Tinh control points cua 1 doi tuong 2d dua vao diem dau va diem cuoi 
        private void calCtrlPoints(List<Point> lst, DRAWING_MODE sh, out List<Point> res)
        {
            // Control Point duoc tra ve o dang list ca points
            res = new List<Point>();

            // Cac hinh deu co 8 control points except polygon va line
            if (sh != DRAWING_MODE.POLYGON)
            {
                Point p1 = new Point(lst[0].X, lst[0].Y);
                Point p2 = new Point(lst[1].X, lst[1].Y);

                // Control points duong thang: 2 diem
                if (sh == DRAWING_MODE.LINE)
                {

                    res.Add(p1);
                    res.Add(p2);
                }
                else
                {
                    int x1, y1;
                    int x2, y2;
                    int avgX;
                    int avgY;

                    // Control points ellipse va hinh chu nhat
                    if (sh == DRAWING_MODE.ELLIPSE || sh == DRAWING_MODE.RECTANGLE)
                    {
                        x1 = p1.X; y1 = p1.Y;// Toa do diem dau: (x1, y1)
                        x2 = p2.X; y2 = p2.Y;// Toa do diem cuoi: (x2, y2)

                        avgX = (int)((x1 + x2) / 2.0);
                        avgY = (int)((y1 + y2) / 2.0);

                        // 8 control points
                        res.Add(p1);
                        res.Add(new Point(avgX, y1));
                        res.Add(new Point(x2, y1));
                        res.Add(new Point(x2, avgY));
                        res.Add(new Point(x2, y2));
                        res.Add(new Point(avgX, y2));
                        res.Add(new Point(x1, y2));
                        res.Add(new Point(x1, avgY));
                    }
                    else
                    {
                        // Cac hinh bien thien deu (tron, tam giac deu, ngu giac deu, luc giac deu)
                        // 8 Control point se la hinh vuong ngoai tiep

                        if (sh == DRAWING_MODE.CIRCLE)
                        {


                            x1 = p1.X; y1 = p1.Y; // Toa do diem dau (x1, y1)
                            x2 = p2.X; y2 = p2.Y; // Toa do diem cuoi (x2, y2)

                            avgX = (int)((x1 + x2) / 2.0);
                            avgY = (int)((y1 + y2) / 2.0);

                            res.Add(new Point(x1, y1));
                            res.Add(new Point(avgX, y1));
                            res.Add(new Point(x2, y1));
                            res.Add(new Point(x2, avgY));
                            res.Add(new Point(x2, y2));
                            res.Add(new Point(avgX, y2));
                            res.Add(new Point(x1, y2));
                            res.Add(new Point(x1, avgY));

                        }
                        else if (sh == DRAWING_MODE.EQUIL_TRIANGLE)
                        {

                            OpenGL gl = openGLControl.OpenGL;

                            // Tinh lai begPoint, endPoint
                            p1 = new Point(p1.X, gl.RenderContextProvider.Height - p1.Y);
                            p2 = new Point(p2.X, gl.RenderContextProvider.Height - p2.Y);

                            double r;
                            getDistance(p1, p2, out r);
                            r = r / (2 * Math.Sqrt(2));

                            int xc = (p1.X + p2.X) / 2;
                            int yc = (p1.Y + p2.Y) / 2;

                            // Gia su xet tai tam 0(0, 0)
                            int x = 0;
                            int y = (int)r;

                            Point pV1, pV2, pV3;

                            // Doi ve radian
                            double alpha_rad = 0 * Math.PI / 180;
                            pV1 = new Point((int)(xc + x * Math.Cos(alpha_rad) - y * Math.Sin(alpha_rad))
                            , (int)(yc + x * Math.Sin(alpha_rad) + y * Math.Cos(alpha_rad)));

                            alpha_rad = 120 * Math.PI / 180;
                            pV2 = new Point((int)(xc + x * Math.Cos(alpha_rad) - y * Math.Sin(alpha_rad))
                                    , (int)(yc + x * Math.Sin(alpha_rad) + y * Math.Cos(alpha_rad)));

                            alpha_rad = 240 * Math.PI / 180;
                            pV3 = new Point((int)(xc + x * Math.Cos(alpha_rad) - y * Math.Sin(alpha_rad))
                                    , (int)(yc + x * Math.Sin(alpha_rad) + y * Math.Cos(alpha_rad)));

                            x1 = pV2.X; y1 = gl.RenderContextProvider.Height - pV1.Y;
                            x2 = pV3.X; y2 = gl.RenderContextProvider.Height - pV3.Y;

                            avgX = (int)((x1 + x2) / 2.0);
                            avgY = (int)((y1 + y2) / 2.0);

                            // 8 control points
                            res.Add(new Point(x1, y1));
                            res.Add(new Point(avgX, y1));
                            res.Add(new Point(x2, y1));
                            res.Add(new Point(x2, avgY));
                            res.Add(new Point(x2, y2));
                            res.Add(new Point(avgX, y2));
                            res.Add(new Point(x1, y2));
                            res.Add(new Point(x1, avgY));
                        }
                        else if (sh == DRAWING_MODE.PENTAGON)
                        {
                            OpenGL gl = openGLControl.OpenGL;

                            p1 = new Point(p1.X, gl.RenderContextProvider.Height - p1.Y);
                            p2 = new Point(p2.X, gl.RenderContextProvider.Height - p2.Y);

                            double r;
                            getDistance(p1, p2, out r);
                            r = r / (2 * Math.Sqrt(2));

                            int xc = (p1.X + p2.X) / 2;
                            int yc = (p1.Y + p2.Y) / 2;

                            int x = 0;
                            int y = (int)r;

                            Point pV3;

                            // Đổi về radian
                            double alpha_rad = 144 * Math.PI / 180;
                            pV3 = new Point((int)(xc + x * Math.Cos(alpha_rad) - y * Math.Sin(alpha_rad))
                            , (int)(yc + x * Math.Sin(alpha_rad) + y * Math.Cos(alpha_rad)));


                            // Tinh x1, y1 va x2, y2
                            // Va tinh lai toa do y cua 2 diem do do ham drawFillRec no tu dong mac dinh toa do truyen vao la cua winform
                            x1 = p1.X; y1 = gl.RenderContextProvider.Height - p1.Y;
                            x2 = p2.X; y2 = gl.RenderContextProvider.Height - pV3.Y;

                            avgX = (int)((x1 + x2) / 2.0);
                            avgY = (int)((y1 + y2) / 2.0);

                            // 8 control points
                            res.Add(new Point(x1, y1));
                            res.Add(new Point(avgX, y1));
                            res.Add(new Point(x2, y1));
                            res.Add(new Point(x2, avgY));
                            res.Add(new Point(x2, y2));
                            res.Add(new Point(avgX, y2));
                            res.Add(new Point(x1, y2));
                            res.Add(new Point(x1, avgY));
                        }
                        else if (sh == DRAWING_MODE.HEXAGON)
                        {
                            OpenGL gl = openGLControl.OpenGL;

                            p1 = new Point(p1.X, gl.RenderContextProvider.Height - p1.Y);
                            p2 = new Point(p2.X, gl.RenderContextProvider.Height - p2.Y);

                            double r;
                            getDistance(p1, p2, out r);
                            r = r / (2 * Math.Sqrt(2));

                            int xc = (p1.X + p2.X) / 2;
                            int yc = (p1.Y + p2.Y) / 2;

                            int x = 0;
                            int y = (int)r;

                            Point pV2, pV6;

                            double alpha_rad = 60 * Math.PI / 180;
                            pV2 = new Point((int)(xc + x * Math.Cos(alpha_rad) - y * Math.Sin(alpha_rad))
                            , (int)(yc + x * Math.Sin(alpha_rad) + y * Math.Cos(alpha_rad)));

                            alpha_rad = 300 * Math.PI / 180;
                            pV6 = new Point((int)(xc + x * Math.Cos(alpha_rad) - y * Math.Sin(alpha_rad))
                            , (int)(yc + x * Math.Sin(alpha_rad) + y * Math.Cos(alpha_rad)));


                            x1 = pV2.X; y1 = gl.RenderContextProvider.Height - p1.Y;
                            x2 = pV6.X; y2 = gl.RenderContextProvider.Height - p2.Y;

                            avgX = (int)((x1 + x2) / 2.0);
                            avgY = (int)((y1 + y2) / 2.0);

                            res.Add(new Point(x1, y1));
                            res.Add(new Point(avgX, y1));
                            res.Add(new Point(x2, y1));
                            res.Add(new Point(x2, avgY));
                            res.Add(new Point(x2, y2));
                            res.Add(new Point(avgX, y2));
                            res.Add(new Point(x1, y2));
                            res.Add(new Point(x1, avgY));
                        }
                    }
                }
            }
            // Doi voi control points cua da giac, ta tim Xmin/max, Ymin/max de gioi han da giac  
            else if (sh == DRAWING_MODE.POLYGON)
            {
                int Xmin, Xmax, Ymin, Ymax;
                Xmin = Xmax = -1;
                Ymin = Ymax = -1;
                for (int i = 0; i < lst.Count; i++)
                {
                    if (Xmin == -1 || Xmin > lst[i].X)
                        Xmin = lst[i].X;
                    if (Xmax == -1 || Xmax < lst[i].X)
                        Xmax = lst[i].X;
                    if (Ymin == -1 || Ymin > lst[i].Y)
                        Ymin = lst[i].Y;
                    if (Ymax == -1 || Ymax < lst[i].Y)
                        Ymax = lst[i].Y;
                }


                int x1, x2;
                int y1, y2;

                // tinh lai diem dau/cuoi
                x1 = Xmin; y1 = Ymax;// diem dau (Xmin, Ymax)
                x2 = Xmax; y2 = Ymin;// diem cuoi(Xmax, Ymin)

                int avgX, avgY;

                avgX = (int)((x1 + x2) / 2.0);
                avgY = (int)((y1 + y2) / 2.0);

                res.Add(new Point(x1, y1));
                res.Add(new Point(avgX, y1));
                res.Add(new Point(x2, y1));
                res.Add(new Point(x2, avgY));
                res.Add(new Point(x2, y2));
                res.Add(new Point(avgX, y2));
                res.Add(new Point(x1, y2));
                res.Add(new Point(x1, avgY));
            }
        }


        // Kiem tra xem 1 point co thuoc 1 doi tuonng 2d da ve khong
        private void check_pointInObject(Point p, int Xmin, int Xmax, int Ymin, int Ymax, out bool res)
        {
            if ((Xmin <= p.X && p.X <= Xmax) && (Ymin <= p.Y && p.Y <= Ymax))
                res = true;
            else
                res = false;
        }

        // Xu ly chon control points
        // Output: doi tuong va vi tri doi tương trong list curRaster
        private void select2dObject(Point seed, out myRaster obj, out int index)
        {
            obj = new myRaster(); // Khoi tao truoc doi tuong
            index = -1;
            double dmin = -1;
            int imin = -1; // Ban dau mac dinh chi so la -1
            int h = openGLControl.OpenGL.RenderContextProvider.Height; // Lay chieu cao cua cua so
            for (int i = 0; i < curRaster.Count; i++)
            {
                bool flag;
                int Xmin, Xmax;
                int Ymin, Ymax;
                if (curRaster[i].raster_toolMode != DRAWING_MODE.POLYGON)
                {
                    Point p1, p2;
                    p1 = curRaster[i].controlPoints[0];
                    p2 = curRaster[i].controlPoints[1];

                    if (p1.X < p2.X)
                    {
                        Xmin = p1.X;
                        Xmax = p2.X;
                    }
                    else
                    {
                        Xmin = p2.X;
                        Xmax = p1.X;
                    }

                    if (p1.Y < p2.Y)
                    {
                        Ymin = p1.Y;
                        Ymax = p2.Y;
                    }
                    else
                    {
                        Ymin = p2.Y;
                        Ymax = p1.Y;
                    }


                }
                else
                {
                    // Da giac: khoanh vung bang Xmin/max, Ymin/max
                    Xmin = Xmax = -1;
                    Ymin = Ymax = -1;
                    List<Point> lst = new List<Point>();
                    lst.AddRange(curRaster[i].controlPoints);
                    for (int j = 0; j < lst.Count; j++)
                    {
                        if (Xmin == -1 || Xmin > lst[j].X)
                            Xmin = lst[j].X;
                        if (Xmax == -1 || Xmax < lst[j].X)
                            Xmax = lst[j].X;
                        if (Ymin == -1 || Ymin > lst[j].Y)
                            Ymin = lst[j].Y;
                        if (Ymax == -1 || Ymax < lst[j].Y)
                            Ymax = lst[j].Y;
                    }

                }
                check_pointInObject(tmpStart, Xmin, Xmax, Ymin, Ymax, out flag);
                if (flag)
                {
                    double d;
                    Point midpoint = new Point((int)((Xmin + Xmax) / 2.0), (int)((Ymin + Ymax) / 2.0));
                    getDistance(seed, midpoint, out d);
                    if (dmin == -1 || d < dmin)
                    {
                        dmin = d;
                        imin = i;
                    }
                }
            }

            if (imin != -1)
            {
                obj = new myRaster(curRaster[imin]);
                index = imin;
            }
        }

        #endregion



        private void preDraw(OpenGL gl)
        {
            for (int i = 0; i < curRaster.Count; i++)
            {
                // KHoi tao 2 bien p1, p2
                Point p1, p2;

                // Chon mau
                gl.Color(curRaster[i].rasterColor.R / 255.0, curRaster[i].rasterColor.G / 255.0, curRaster[i].rasterColor.B / 255.0, 0);
                // Thiet lap size cua net ve
                gl.LineWidth(curRaster[i].rasterSize);

                switch (curRaster[i].raster_toolMode)
                {
                    case DRAWING_MODE.LINE:
                        // Ve doan thang
                        p1 = new Point(curRaster[i].controlPoints[0].X, curRaster[i].controlPoints[0].Y);
                        p2 = new Point(curRaster[i].controlPoints[1].X, curRaster[i].controlPoints[1].Y);
                        drawLine(gl, p1, p2);
                        break;
                    case DRAWING_MODE.CIRCLE:
                        // Ve duong tron
                        p1 = new Point(curRaster[i].controlPoints[0].X, curRaster[i].controlPoints[0].Y);
                        p2 = new Point(curRaster[i].controlPoints[1].X, curRaster[i].controlPoints[1].Y);
                        drawCircle(gl, p1, p2);
                        break;
                    case DRAWING_MODE.RECTANGLE:
                        // Ve hinh chu nhat
                        p1 = new Point(curRaster[i].controlPoints[0].X, curRaster[i].controlPoints[0].Y);
                        p2 = new Point(curRaster[i].controlPoints[1].X, curRaster[i].controlPoints[1].Y);
                        drawRec(gl, p1, p2);
                        break;
                    case DRAWING_MODE.ELLIPSE:
                        // Ve ellipse
                        p1 = new Point(curRaster[i].controlPoints[0].X, curRaster[i].controlPoints[0].Y);
                        p2 = new Point(curRaster[i].controlPoints[1].X, curRaster[i].controlPoints[1].Y);
                        drawEllipse(gl, p1, p2);
                        break;
                    case DRAWING_MODE.EQUIL_TRIANGLE:
                        // Ve tam giac deu
                        p1 = new Point(curRaster[i].controlPoints[0].X, curRaster[i].controlPoints[0].Y);
                        p2 = new Point(curRaster[i].controlPoints[1].X, curRaster[i].controlPoints[1].Y);
                        drawTriangle(gl, p1, p2);
                        break;
                    case DRAWING_MODE.PENTAGON:
                        // Ve ngu giac deu
                        p1 = new Point(curRaster[i].controlPoints[0].X, curRaster[i].controlPoints[0].Y);
                        p2 = new Point(curRaster[i].controlPoints[1].X, curRaster[i].controlPoints[1].Y);
                        drawPentagon(gl, p1, p2);
                        break;
                    case DRAWING_MODE.HEXAGON:
                        // Ve luc giac deu
                        p1 = new Point(curRaster[i].controlPoints[0].X, curRaster[i].controlPoints[0].Y);
                        p2 = new Point(curRaster[i].controlPoints[1].X, curRaster[i].controlPoints[1].Y);
                        drawHexagon(gl, p1, p2);
                        break;
                    case DRAWING_MODE.POLYGON:
                        // Ve da giac
                        drawPolygon(gl, curRaster[i].controlPoints);
                        break;
                    case DRAWING_MODE.FLOOD_FILL:
                        p1 = new Point(curRaster[i].controlPoints[0].X, curRaster[i].controlPoints[0].Y);
                        // To mau bang thuat toan flood fill
                        floodFill(gl, p1.X, p1.Y, curRaster[i].rasterColor, Color.Black);
                        break;
                }
            }
        }

        //____________________________________Ham xu ly ve chinh____________________________________
        #region Xu ly OPENGL
        private void openGLControl_OpenGLDraw(object sender, RenderEventArgs args)
        {

            if (isMouseDown) // Neu nguoi dung dang Mouse down thi moi ve
            {
                // get the OpenGL object
                OpenGL gl = openGLControl.OpenGL;
                // clear the color and depth buffer
                gl.Clear(OpenGL.GL_COLOR_BUFFER_BIT | OpenGL.GL_DEPTH_BUFFER_BIT);

                preDraw(gl);

                if (curTool == SharpGL.TOOLS_MODE.SELECT_CTRLPOINT)
                {
                    // Select
                    myRaster obj;
                    int index;
                    select2dObject(tmpStart, out obj, out index);
                    // Kiem tra xem co null hay khong?
                    bool isNull = false;
                    obj.isNull(out isNull);
                    if (!isNull)
                    {
                        drawCtrlPoints(obj.controlPoints, obj.raster_toolMode); // Ve cac control point cua hinh do
                        if (select_changeSize || select_changeColor)
                        {
                            curRaster.RemoveAt(index); // Xoa khoi list

                            if (select_changeSize)
                            {   // Cap nhat size
                                curRaster.Add(new myRaster(obj.controlPoints, obj.rasterColor, obj.raster_toolMode, curSize));
                                select_changeSize = false;
                            }
                            else if (select_changeColor)
                            { // cap nhat mau ve
                                curRaster.Add(new myRaster(obj.controlPoints, curColor, obj.raster_toolMode, obj.rasterSize));
                                select_changeColor = false;
                            }
                        }

                    }
                }

                // Chon mau
                gl.Color(curColor.R / 255.0, curColor.G / 255.0, curColor.B / 255.0, 0);
                // Thiet lap size cua net ve
                gl.LineWidth(curSize);

                // Stopwatch ho tro do thoi gian
                Stopwatch myTimer = new Stopwatch();
                if (curTool == SharpGL.TOOLS_MODE.DRAWING)
                    myTimer.Start(); // bat dau do

                if (curTool == SharpGL.TOOLS_MODE.TRANSLATE)
                {
                    if (isSelected == false)
                    {
                        myRaster obj;

                        select2dObject(tmpStart, out obj, out tmpObject);
                        // Kiem tra xem co null hay khong?
                        bool isNull = false;
                        obj.isNull(out isNull);
                        if (!isNull)
                        {
                            drawCtrlPoints(obj.controlPoints, obj.raster_toolMode);
                            curShape = obj.raster_toolMode;
                            curColor = obj.rasterColor;
                            curSize = obj.rasterSize;
                            begPoint = obj.controlPoints[0];
                            endPoint = obj.controlPoints[1];

                            // Xoa doi tuong khoi raster
                            curRaster.RemoveAt(tmpObject);
                            isSelected = true;
                        }
                    }
                    translate(gl);

                }
                else if (curTool == SharpGL.TOOLS_MODE.ROTATE)
                {
                    if (isSelected == false)
                    {
                        myRaster obj;
                        select2dObject(tmpStart, out obj, out tmpObject);
                        // Kiem tra xem co null hay khong?
                        bool isNull = false;
                        obj.isNull(out isNull);
                        if (!isNull)
                        {
                            drawCtrlPoints(obj.controlPoints, obj.raster_toolMode);
                            curShape = obj.raster_toolMode;
                            curColor = obj.rasterColor;
                            curSize = obj.rasterSize;
                            begPoint = obj.controlPoints[0];
                            endPoint = obj.controlPoints[1];

                            curRaster.RemoveAt(tmpObject);
                            isSelected = true;
                        }
                    }
                    rotate(gl);
                }

                // Ve hinh
                switch (curShape)
                {
                    case DRAWING_MODE.LINE:
                        drawLine(gl, begPoint, endPoint);
                        break;
                    case DRAWING_MODE.CIRCLE:
                        drawCircle(gl, begPoint, endPoint);
                        break;
                    case DRAWING_MODE.RECTANGLE:
                        drawRec(gl, begPoint, endPoint);
                        break;
                    case DRAWING_MODE.ELLIPSE:
                        drawEllipse(gl, begPoint, endPoint);
                        break;
                    case DRAWING_MODE.EQUIL_TRIANGLE:
                        drawTriangle(gl, begPoint, endPoint);
                        break;
                    case DRAWING_MODE.PENTAGON:
                        drawPentagon(gl, begPoint, endPoint);
                        break;
                    case DRAWING_MODE.HEXAGON:
                        drawHexagon(gl, begPoint, endPoint);
                        break;
                    case DRAWING_MODE.POLYGON:
                        if (curTool == SharpGL.TOOLS_MODE.DRAWING)
                            drawPolygon(gl);
                        break;
                    case DRAWING_MODE.FLOOD_FILL:
                        // To mau bang thuat toan flood fill

                        Byte[] pixel = new Byte[4];
                        getPixelColor(gl, begPoint.X, begPoint.Y, out pixel);
                        Color old_color = new Color();
                        old_color = Color.FromArgb(pixel[3], pixel[0], pixel[1], pixel[2]);
                        floodFill(gl, begPoint.X, begPoint.Y, curColor, old_color);
                        break;
                }

                if (curTool == SharpGL.TOOLS_MODE.DRAWING)
                {
                    myTimer.Stop(); // ket thuc do
                    TimeSpan Time = myTimer.Elapsed;
                    tb_Time.Text = String.Format("{0} (giây)", Time.TotalSeconds);
                }

                if (isAffineTrans == true)
                {
                    gl.PopMatrix();
                }

            }
        }

        private void openGLControl_Resized(object sender, EventArgs e)
        {
            // get the OpenGL object
            OpenGL gl = openGLControl.OpenGL;
            // set the projection matrix
            gl.MatrixMode(OpenGL.GL_PROJECTION);
            // load the identify
            gl.LoadIdentity();
            // Create a perspective transformation
            gl.Viewport(0, 0, openGLControl.Width, openGLControl.Height);
            gl.Ortho2D(0, openGLControl.Width, 0, openGLControl.Height);
        }

        #endregion

        //____________________________________Flood fill____________________________________
        #region Flood fill
        // Bo tro flood fill
        private void getPixelColor(OpenGL gl, int x, int y, out Byte[] color)
        {
            color = new Byte[4 * 1 * 1];
            gl.ReadPixels(x, gl.RenderContextProvider.Height - y, 1, 1, OpenGL.GL_RGBA, OpenGL.GL_UNSIGNED_BYTE, color);
        }

        private void setPixelColor(OpenGL gl, int x, int y, Color fill_color)
        {
            gl.Color(fill_color.R / 255.0, fill_color.G / 255.0, fill_color.B / 255.0, fill_color.A);
            gl.PointSize(2);
            gl.Begin(OpenGL.GL_POINTS);
            gl.Vertex(x, gl.RenderContextProvider.Height - y);
            gl.End();
            gl.Flush();
        }


        // Ham to mau theo vet loang
        private void floodFill(OpenGL gl, int x, int y, Color fill_color, Color old_color)
        {
            if (fill_color == old_color) return; // Tranh lap vo han

            int[] dx = new int[] { 0, 2, 0, -2 }; // Cac nhanh lan can 4 cua x
            int[] dy = new int[] { -2, 0, 2, 0 }; // Cac nhanh lan can 4 cua y

            Stack<Point> s = new Stack<Point>(); // Khoi tao stack
            s.Push(new Point(x, y)); // Push diem dau vao Stack

            while (s.Count != 0)
            { // Khi stack khac rong
                Point p = s.Pop(); // Pop ra khoi stack
                setPixelColor(gl, p.X, p.Y, fill_color); //To mau
                for (int i = 0; i < 4; i++)
                {
                    int nx = p.X + dx[i];
                    int ny = p.Y + dy[i];
                    // Lay pixel cua nx, ny
                    Byte[] neighbor_color;
                    getPixelColor(gl, nx, ny, out neighbor_color);
                    // Neu nhu nx, ny chua to thi push vao stack
                    if (neighbor_color[0] == old_color.R && neighbor_color[1] == old_color.G && neighbor_color[2] == old_color.B
                        && neighbor_color[3] == old_color.A)
                    {
                        s.Push(new Point(nx, ny));
                    }
                }

            }
        }

        #endregion

        // Ham translate
        private void translate(OpenGL gl)
        {
            gl.PushMatrix();
            int xSpan = tmpEnd.X - tmpStart.X;
            int ySpan = -tmpEnd.Y + tmpStart.Y;
            gl.Translate(xSpan, ySpan, 0);
            isAffineTrans = true;
        }


        // Ham rotate
        private void rotate(OpenGL gl)
        {
            int height = gl.RenderContextProvider.Height;
            Point CenterRotate = new Point((begPoint.X + endPoint.X) / 2, (begPoint.Y + endPoint.Y) / 2);

            double rotateAngle = 0;
            int[] vector1 = { 0, 1 };
            int[] vector2 = { tmpEnd.X - CenterRotate.X, -tmpEnd.Y + CenterRotate.Y };

            double length_vector1 = Math.Sqrt(Math.Pow(vector1[0], 2) + Math.Pow(vector1[1], 2));
            double length_vector2 = Math.Sqrt(Math.Pow(vector2[0], 2) + Math.Pow(vector2[1], 2));

            int num = vector1[0] * vector2[0] + vector1[1] * vector2[1];
            double deno = length_vector1 * length_vector2;
            rotateAngle = Math.Acos(num / deno) * 180 / Math.PI;

            if (tmpEnd.X > CenterRotate.X)
                rotateAngle = -rotateAngle;

            gl.PushMatrix();
            gl.Translate(CenterRotate.X, gl.RenderContextProvider.Height - CenterRotate.Y, 0f);
            gl.Rotate(rotateAngle, 0, 0, 1);
            gl.Translate(-CenterRotate.X, CenterRotate.Y - gl.RenderContextProvider.Height, 0f);
            isAffineTrans = true;
        }
    }
}
