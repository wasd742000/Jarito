namespace SharpGL
{
    partial class Lab3_Form
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Lab3_Form));
            this.openGLControl = new SharpGL.OpenGLControl();
            this.Icon_List = new System.Windows.Forms.ImageList(this.components);
            this.bt_ColorTable = new System.Windows.Forms.Button();
            this.colorDialog1 = new System.Windows.Forms.ColorDialog();
            this.lb_Time = new System.Windows.Forms.Label();
            this.tb_Time = new System.Windows.Forms.TextBox();
            this.pnl_Tool_Bar = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.comboBox_changeMode = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.bt_Rectangle = new System.Windows.Forms.Button();
            this.bt_Line = new System.Windows.Forms.Button();
            this.bt_Pentagon = new System.Windows.Forms.Button();
            this.bt_Triangle = new System.Windows.Forms.Button();
            this.bt_Polygon = new System.Windows.Forms.Button();
            this.lb_Flood_Fill = new System.Windows.Forms.Label();
            this.bt_Ellipse = new System.Windows.Forms.Button();
            this.lb_Color1 = new System.Windows.Forms.Label();
            this.bt_CurrentColor = new System.Windows.Forms.Button();
            this.lb_Size = new System.Windows.Forms.Label();
            this.bt_Hexagon = new System.Windows.Forms.Button();
            this.comboBox_ChangeSize = new System.Windows.Forms.ComboBox();
            this.bt_Flood_Fill = new System.Windows.Forms.Button();
            this.bt_Circle = new System.Windows.Forms.Button();
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.openGLControl)).BeginInit();
            this.pnl_Tool_Bar.SuspendLayout();
            this.SuspendLayout();
            // 
            // openGLControl
            // 
            this.openGLControl.BackColor = System.Drawing.SystemColors.Window;
            this.openGLControl.Cursor = System.Windows.Forms.Cursors.Hand;
            this.openGLControl.DrawFPS = false;
            this.openGLControl.ForeColor = System.Drawing.SystemColors.Window;
            this.openGLControl.FrameRate = 40;
            this.openGLControl.Location = new System.Drawing.Point(0, 125);
            this.openGLControl.Margin = new System.Windows.Forms.Padding(4);
            this.openGLControl.Name = "openGLControl";
            this.openGLControl.OpenGLVersion = SharpGL.Version.OpenGLVersion.OpenGL2_1;
            this.openGLControl.RenderContextType = SharpGL.RenderContextType.DIBSection;
            this.openGLControl.RenderTrigger = SharpGL.RenderTrigger.TimerBased;
            this.openGLControl.Size = new System.Drawing.Size(1262, 554);
            this.openGLControl.TabIndex = 0;
            this.openGLControl.OpenGLInitialized += new System.EventHandler(this.openGLControl_OpenGLInitialized);
            this.openGLControl.OpenGLDraw += new SharpGL.RenderEventHandler(this.openGLControl_OpenGLDraw);
            this.openGLControl.Resized += new System.EventHandler(this.openGLControl_Resized);
            this.openGLControl.MouseClick += new System.Windows.Forms.MouseEventHandler(this.openGLControl_MouseClick);
            this.openGLControl.MouseDown += new System.Windows.Forms.MouseEventHandler(this.ctrl_OpenGLControl_MouseDown);
            this.openGLControl.MouseHover += new System.EventHandler(this.openGLControl_MouseHover);
            this.openGLControl.MouseMove += new System.Windows.Forms.MouseEventHandler(this.ctrl_OpenGLControl_MouseMove);
            this.openGLControl.MouseUp += new System.Windows.Forms.MouseEventHandler(this.ctrl_OpenGLControl_MouseUp);
            // 
            // Icon_List
            // 
            this.Icon_List.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("Icon_List.ImageStream")));
            this.Icon_List.TransparentColor = System.Drawing.Color.Transparent;
            this.Icon_List.Images.SetKeyName(0, "icons8-line-96.png");
            this.Icon_List.Images.SetKeyName(1, "if_button_shape_triangle_352894.png");
            this.Icon_List.Images.SetKeyName(2, "icons8-rectangular-100.png");
            this.Icon_List.Images.SetKeyName(3, "if_check-circle-outline-blank_326565.png");
            this.Icon_List.Images.SetKeyName(4, "Actions-fill-color-icon.png");
            this.Icon_List.Images.SetKeyName(5, "pentagon- (3).png");
            this.Icon_List.Images.SetKeyName(6, "polygon (1).png");
            this.Icon_List.Images.SetKeyName(7, "hexagon.png");
            // 
            // bt_ColorTable
            // 
            this.bt_ColorTable.BackColor = System.Drawing.Color.White;
            this.bt_ColorTable.Cursor = System.Windows.Forms.Cursors.Hand;
            this.bt_ColorTable.Image = ((System.Drawing.Image)(resources.GetObject("bt_ColorTable.Image")));
            this.bt_ColorTable.Location = new System.Drawing.Point(756, 19);
            this.bt_ColorTable.Name = "bt_ColorTable";
            this.bt_ColorTable.Size = new System.Drawing.Size(64, 64);
            this.bt_ColorTable.TabIndex = 3;
            this.bt_ColorTable.UseVisualStyleBackColor = false;
            this.bt_ColorTable.Click += new System.EventHandler(this.bt_ColorTable_Click);
            // 
            // lb_Time
            // 
            this.lb_Time.AutoSize = true;
            this.lb_Time.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lb_Time.Location = new System.Drawing.Point(1143, 14);
            this.lb_Time.Name = "lb_Time";
            this.lb_Time.Size = new System.Drawing.Size(109, 19);
            this.lb_Time.TabIndex = 4;
            this.lb_Time.Text = "Thời gian vẽ";
            // 
            // tb_Time
            // 
            this.tb_Time.Cursor = System.Windows.Forms.Cursors.No;
            this.tb_Time.HideSelection = false;
            this.tb_Time.Location = new System.Drawing.Point(1152, 42);
            this.tb_Time.Name = "tb_Time";
            this.tb_Time.Size = new System.Drawing.Size(100, 20);
            this.tb_Time.TabIndex = 5;
            this.tb_Time.Text = "         Chưa có";
            // 
            // pnl_Tool_Bar
            // 
            this.pnl_Tool_Bar.BackColor = System.Drawing.Color.LightSteelBlue;
            this.pnl_Tool_Bar.Controls.Add(this.label1);
            this.pnl_Tool_Bar.Controls.Add(this.comboBox_changeMode);
            this.pnl_Tool_Bar.Controls.Add(this.label2);
            this.pnl_Tool_Bar.Controls.Add(this.bt_Rectangle);
            this.pnl_Tool_Bar.Controls.Add(this.bt_Line);
            this.pnl_Tool_Bar.Controls.Add(this.bt_Pentagon);
            this.pnl_Tool_Bar.Controls.Add(this.bt_Triangle);
            this.pnl_Tool_Bar.Controls.Add(this.bt_Polygon);
            this.pnl_Tool_Bar.Controls.Add(this.lb_Flood_Fill);
            this.pnl_Tool_Bar.Controls.Add(this.bt_Ellipse);
            this.pnl_Tool_Bar.Controls.Add(this.lb_Color1);
            this.pnl_Tool_Bar.Controls.Add(this.bt_CurrentColor);
            this.pnl_Tool_Bar.Controls.Add(this.lb_Size);
            this.pnl_Tool_Bar.Controls.Add(this.bt_Hexagon);
            this.pnl_Tool_Bar.Controls.Add(this.comboBox_ChangeSize);
            this.pnl_Tool_Bar.Controls.Add(this.bt_ColorTable);
            this.pnl_Tool_Bar.Controls.Add(this.tb_Time);
            this.pnl_Tool_Bar.Controls.Add(this.lb_Time);
            this.pnl_Tool_Bar.Controls.Add(this.bt_Flood_Fill);
            this.pnl_Tool_Bar.Controls.Add(this.bt_Circle);
            this.pnl_Tool_Bar.Cursor = System.Windows.Forms.Cursors.Default;
            this.pnl_Tool_Bar.Location = new System.Drawing.Point(0, 2);
            this.pnl_Tool_Bar.Name = "pnl_Tool_Bar";
            this.pnl_Tool_Bar.Size = new System.Drawing.Size(1368, 127);
            this.pnl_Tool_Bar.TabIndex = 9;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(568, 11);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(140, 19);
            this.label1.TabIndex = 32;
            this.label1.Text = "Chọn hành động";
            // 
            // comboBox_changeMode
            // 
            this.comboBox_changeMode.CausesValidation = false;
            this.comboBox_changeMode.Cursor = System.Windows.Forms.Cursors.Hand;
            this.comboBox_changeMode.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.comboBox_changeMode.FormattingEnabled = true;
            this.comboBox_changeMode.Items.AddRange(new object[] {
            "Draw",
            "Select object",
            "Translate",
            "Rotate"});
            this.comboBox_changeMode.Location = new System.Drawing.Point(572, 40);
            this.comboBox_changeMode.Name = "comboBox_changeMode";
            this.comboBox_changeMode.Size = new System.Drawing.Size(121, 24);
            this.comboBox_changeMode.TabIndex = 31;
            this.comboBox_changeMode.SelectedIndexChanged += new System.EventHandler(this.comboBox_changeMode_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(743, 89);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(90, 19);
            this.label2.TabIndex = 30;
            this.label2.Text = "Chọn màu\r\n";
            // 
            // bt_Rectangle
            // 
            this.bt_Rectangle.BackColor = System.Drawing.Color.White;
            this.bt_Rectangle.Cursor = System.Windows.Forms.Cursors.Hand;
            this.bt_Rectangle.Image = ((System.Drawing.Image)(resources.GetObject("bt_Rectangle.Image")));
            this.bt_Rectangle.Location = new System.Drawing.Point(107, 14);
            this.bt_Rectangle.Name = "bt_Rectangle";
            this.bt_Rectangle.Size = new System.Drawing.Size(48, 48);
            this.bt_Rectangle.TabIndex = 12;
            this.bt_Rectangle.UseVisualStyleBackColor = false;
            this.bt_Rectangle.Click += new System.EventHandler(this.bt_Rectangle_Click);
            this.bt_Rectangle.MouseHover += new System.EventHandler(this.bt_Rectangle_MouseHover);
            // 
            // bt_Line
            // 
            this.bt_Line.BackColor = System.Drawing.Color.White;
            this.bt_Line.Cursor = System.Windows.Forms.Cursors.Hand;
            this.bt_Line.ForeColor = System.Drawing.Color.Black;
            this.bt_Line.Image = ((System.Drawing.Image)(resources.GetObject("bt_Line.Image")));
            this.bt_Line.Location = new System.Drawing.Point(21, 14);
            this.bt_Line.Name = "bt_Line";
            this.bt_Line.Size = new System.Drawing.Size(48, 48);
            this.bt_Line.TabIndex = 1;
            this.bt_Line.UseVisualStyleBackColor = false;
            this.bt_Line.Click += new System.EventHandler(this.bt_Line_Click);
            this.bt_Line.MouseHover += new System.EventHandler(this.bt_Line_MouseHover);
            // 
            // bt_Pentagon
            // 
            this.bt_Pentagon.BackColor = System.Drawing.Color.White;
            this.bt_Pentagon.Cursor = System.Windows.Forms.Cursors.Hand;
            this.bt_Pentagon.Image = ((System.Drawing.Image)(resources.GetObject("bt_Pentagon.Image")));
            this.bt_Pentagon.Location = new System.Drawing.Point(107, 66);
            this.bt_Pentagon.Name = "bt_Pentagon";
            this.bt_Pentagon.Size = new System.Drawing.Size(48, 48);
            this.bt_Pentagon.TabIndex = 14;
            this.bt_Pentagon.UseVisualStyleBackColor = false;
            this.bt_Pentagon.Click += new System.EventHandler(this.bt_Pentagon_Click);
            this.bt_Pentagon.MouseHover += new System.EventHandler(this.bt_Pentagon_MouseHover);
            // 
            // bt_Triangle
            // 
            this.bt_Triangle.BackColor = System.Drawing.Color.White;
            this.bt_Triangle.Cursor = System.Windows.Forms.Cursors.Hand;
            this.bt_Triangle.Image = ((System.Drawing.Image)(resources.GetObject("bt_Triangle.Image")));
            this.bt_Triangle.Location = new System.Drawing.Point(21, 68);
            this.bt_Triangle.Name = "bt_Triangle";
            this.bt_Triangle.Size = new System.Drawing.Size(48, 48);
            this.bt_Triangle.TabIndex = 11;
            this.bt_Triangle.UseVisualStyleBackColor = false;
            this.bt_Triangle.Click += new System.EventHandler(this.bt_Triangle_Click);
            this.bt_Triangle.MouseHover += new System.EventHandler(this.bt_Triangle_MouseHover);
            // 
            // bt_Polygon
            // 
            this.bt_Polygon.BackColor = System.Drawing.Color.White;
            this.bt_Polygon.Cursor = System.Windows.Forms.Cursors.Hand;
            this.bt_Polygon.Image = ((System.Drawing.Image)(resources.GetObject("bt_Polygon.Image")));
            this.bt_Polygon.Location = new System.Drawing.Point(191, 68);
            this.bt_Polygon.Name = "bt_Polygon";
            this.bt_Polygon.Size = new System.Drawing.Size(48, 48);
            this.bt_Polygon.TabIndex = 23;
            this.bt_Polygon.UseVisualStyleBackColor = false;
            this.bt_Polygon.Click += new System.EventHandler(this.bt_Polygon_Click);
            this.bt_Polygon.MouseHover += new System.EventHandler(this.bt_Polygon_MouseHover);
            // 
            // lb_Flood_Fill
            // 
            this.lb_Flood_Fill.AutoSize = true;
            this.lb_Flood_Fill.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lb_Flood_Fill.Location = new System.Drawing.Point(894, 89);
            this.lb_Flood_Fill.Name = "lb_Flood_Fill";
            this.lb_Flood_Fill.Size = new System.Drawing.Size(70, 19);
            this.lb_Flood_Fill.TabIndex = 22;
            this.lb_Flood_Fill.Text = "Tô màu";
            // 
            // bt_Ellipse
            // 
            this.bt_Ellipse.BackColor = System.Drawing.Color.White;
            this.bt_Ellipse.Cursor = System.Windows.Forms.Cursors.Hand;
            this.bt_Ellipse.Image = ((System.Drawing.Image)(resources.GetObject("bt_Ellipse.Image")));
            this.bt_Ellipse.Location = new System.Drawing.Point(274, 68);
            this.bt_Ellipse.Name = "bt_Ellipse";
            this.bt_Ellipse.Size = new System.Drawing.Size(48, 48);
            this.bt_Ellipse.TabIndex = 21;
            this.bt_Ellipse.UseVisualStyleBackColor = false;
            this.bt_Ellipse.Click += new System.EventHandler(this.bt_Ellipse_Click);
            this.bt_Ellipse.MouseHover += new System.EventHandler(this.bt_Ellipse_MouseHover);
            // 
            // lb_Color1
            // 
            this.lb_Color1.AutoSize = true;
            this.lb_Color1.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lb_Color1.Location = new System.Drawing.Point(1030, 14);
            this.lb_Color1.Name = "lb_Color1";
            this.lb_Color1.Size = new System.Drawing.Size(110, 19);
            this.lb_Color1.TabIndex = 19;
            this.lb_Color1.Text = "Màu hiện tại";
            // 
            // bt_CurrentColor
            // 
            this.bt_CurrentColor.BackColor = System.Drawing.Color.Black;
            this.bt_CurrentColor.Cursor = System.Windows.Forms.Cursors.No;
            this.bt_CurrentColor.Location = new System.Drawing.Point(1050, 35);
            this.bt_CurrentColor.Name = "bt_CurrentColor";
            this.bt_CurrentColor.Size = new System.Drawing.Size(70, 70);
            this.bt_CurrentColor.TabIndex = 17;
            this.bt_CurrentColor.UseVisualStyleBackColor = false;
            // 
            // lb_Size
            // 
            this.lb_Size.AutoSize = true;
            this.lb_Size.Font = new System.Drawing.Font("Tahoma", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lb_Size.Location = new System.Drawing.Point(365, 11);
            this.lb_Size.Name = "lb_Size";
            this.lb_Size.Size = new System.Drawing.Size(167, 19);
            this.lb_Size.TabIndex = 16;
            this.lb_Size.Text = "Chọn kích cỡ nét vẽ";
            // 
            // bt_Hexagon
            // 
            this.bt_Hexagon.BackColor = System.Drawing.Color.White;
            this.bt_Hexagon.Cursor = System.Windows.Forms.Cursors.Hand;
            this.bt_Hexagon.Image = ((System.Drawing.Image)(resources.GetObject("bt_Hexagon.Image")));
            this.bt_Hexagon.Location = new System.Drawing.Point(191, 14);
            this.bt_Hexagon.Name = "bt_Hexagon";
            this.bt_Hexagon.Size = new System.Drawing.Size(48, 48);
            this.bt_Hexagon.TabIndex = 15;
            this.bt_Hexagon.UseVisualStyleBackColor = false;
            this.bt_Hexagon.Click += new System.EventHandler(this.bt_Hexagon_Click);
            this.bt_Hexagon.MouseHover += new System.EventHandler(this.bt_Hexagon_MouseHover);
            // 
            // comboBox_ChangeSize
            // 
            this.comboBox_ChangeSize.CausesValidation = false;
            this.comboBox_ChangeSize.Cursor = System.Windows.Forms.Cursors.Hand;
            this.comboBox_ChangeSize.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.comboBox_ChangeSize.FormattingEnabled = true;
            this.comboBox_ChangeSize.Items.AddRange(new object[] {
            "1",
            "2",
            "3",
            "4",
            "5",
            "6",
            "7",
            "8",
            "9",
            "10"});
            this.comboBox_ChangeSize.Location = new System.Drawing.Point(386, 40);
            this.comboBox_ChangeSize.Name = "comboBox_ChangeSize";
            this.comboBox_ChangeSize.Size = new System.Drawing.Size(121, 24);
            this.comboBox_ChangeSize.TabIndex = 13;
            this.comboBox_ChangeSize.SelectedIndexChanged += new System.EventHandler(this.comboBox_changeSize_click);
            // 
            // bt_Flood_Fill
            // 
            this.bt_Flood_Fill.BackColor = System.Drawing.SystemColors.Window;
            this.bt_Flood_Fill.Cursor = System.Windows.Forms.Cursors.Hand;
            this.bt_Flood_Fill.ForeColor = System.Drawing.Color.Black;
            this.bt_Flood_Fill.Image = ((System.Drawing.Image)(resources.GetObject("bt_Flood_Fill.Image")));
            this.bt_Flood_Fill.Location = new System.Drawing.Point(898, 19);
            this.bt_Flood_Fill.Name = "bt_Flood_Fill";
            this.bt_Flood_Fill.Size = new System.Drawing.Size(64, 64);
            this.bt_Flood_Fill.TabIndex = 8;
            this.bt_Flood_Fill.UseVisualStyleBackColor = false;
            this.bt_Flood_Fill.Click += new System.EventHandler(this.bt_Flood_Fill_Click);
            // 
            // bt_Circle
            // 
            this.bt_Circle.BackColor = System.Drawing.Color.White;
            this.bt_Circle.Cursor = System.Windows.Forms.Cursors.Hand;
            this.bt_Circle.Image = ((System.Drawing.Image)(resources.GetObject("bt_Circle.Image")));
            this.bt_Circle.Location = new System.Drawing.Point(274, 14);
            this.bt_Circle.Name = "bt_Circle";
            this.bt_Circle.Size = new System.Drawing.Size(48, 48);
            this.bt_Circle.TabIndex = 2;
            this.bt_Circle.UseVisualStyleBackColor = false;
            this.bt_Circle.Click += new System.EventHandler(this.bt_Circle_Click);
            this.bt_Circle.MouseHover += new System.EventHandler(this.bt_Circle_MouseHover);
            // 
            // Form_Paint
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1264, 681);
            this.Controls.Add(this.pnl_Tool_Bar);
            this.Controls.Add(this.openGLControl);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form_Paint";
            this.Text = "Paint";
            ((System.ComponentModel.ISupportInitialize)(this.openGLControl)).EndInit();
            this.pnl_Tool_Bar.ResumeLayout(false);
            this.pnl_Tool_Bar.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private OpenGLControl openGLControl;
        private System.Windows.Forms.Button bt_Circle;
        private System.Windows.Forms.Button bt_ColorTable;
        private System.Windows.Forms.ColorDialog colorDialog1;
        private System.Windows.Forms.Label lb_Time;
        private System.Windows.Forms.TextBox tb_Time;
        private System.Windows.Forms.Button bt_Flood_Fill;
        private System.Windows.Forms.ImageList Icon_List;
        private System.Windows.Forms.ComboBox comboBox_ChangeSize;
        private System.Windows.Forms.Panel pnl_Tool_Bar;
        private System.Windows.Forms.Button bt_Hexagon;
        private System.Windows.Forms.Label lb_Size;
        private System.Windows.Forms.Button bt_CurrentColor;
        private System.Windows.Forms.Label lb_Color1;
        private System.Windows.Forms.Button bt_Ellipse;
        private System.Windows.Forms.Label lb_Flood_Fill;
        private System.Windows.Forms.Button bt_Polygon;
        private System.Windows.Forms.Button bt_Rectangle;
        private System.Windows.Forms.Button bt_Line;
        private System.Windows.Forms.Button bt_Pentagon;
        private System.Windows.Forms.Button bt_Triangle;
        private System.Windows.Forms.ToolTip toolTip1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.ComboBox comboBox_changeMode;
    }
}

