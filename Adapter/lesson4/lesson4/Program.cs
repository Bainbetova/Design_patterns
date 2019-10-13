using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace lesson4
{
    public class Point
    {
        public int x, y;
        public Point()
        {
            x = 0;
            y = 0;
        }
    };

    public class Figure
    {
        public Point origin = new Point();
        public Point extent = new Point();
        public Figure() {}

        public void move(int a, int b)
        {
            origin.x = a;
            origin.y = b;
        }

        public void size(int a, int b)
        {
            extent.x = a;
            extent.y = b;
        }

        public void draw() { }
    }

    public class Circle : Figure
    {
        public Circle() { }
        public new void draw()
        {
            Console.Write("(");
            Console.Write(origin.x);
            Console.Write(", ");
            Console.Write(origin.y);
            Console.Write(") - (");
            Console.Write(extent.x);
            Console.Write(", ");
            Console.Write(extent.y);
            Console.Write(") - ");
            Console.Write("circle\n");
        }
    }

    public class Square : Figure
    {
        public Square()
        {
        }
        public new void draw()
        {
            Console.Write("(");
            Console.Write(origin.x);
            Console.Write(", ");
            Console.Write(origin.y);
            Console.Write(") - (");
            Console.Write(extent.x);
            Console.Write(", ");
            Console.Write(extent.y);
            Console.Write(") - ");
            Console.Write("square\n");
        }
    }

    public class Paint
    {
        private Figure[] figures = new Figure[6];
        private int count;
        public Paint()
        {
            this.count = 0;
        }

        // добавлениe новой фигуры 
        public void add(Figure f)
        {
            figures[count] = f;
            count++;
        }
        // рисование всех фигур 
        public void draw()
        {
            for (int i = 0; i < count; i++)
            {
                figures[i].draw();
            }
        }
        // получение фигуры 
        public Figure get(int index)
        {
            return figures[index];
        }
    }

    public class Text
    {
        protected string text;
        protected int len;
        protected int x;
        protected int y;
        protected int w;
        protected int h;

        public Text()
        {
            this.x = 0;
            this.y = 0;
            this.w = 0;
            this.h = 0;
        }

        public Text(string T)
        {
            setText(T);
        }       

        public void setText(string T)
        {
            text = T;
        }

        public string getText()
        {
            return text;
        }

        public void SetLocation(int X, int Y)
        {
            x = X;
            y = Y;
        }

        public int GetX()
        {
            return x;
        }

        public int GetY()
        {
            return y;
        }

        public int GetW()
        {
            return text.Length;
        }

        public int GetH()
        {
            return 1;
        }

        public void OutText()
        {
            Console.Write(text);
            Console.Write("\n");
        }

    }

    class FigureText : Figure
    {
        private Text tt = new Text();

        public FigureText(Text txt) {
            tt = txt;
        }
        
        public void move(int a, int b)
        {
            tt.SetLocation(a, b);            
        }
        public void draw()
        {
            Console.Write("(");
            Console.Write(tt.GetX());
            Console.Write(", ");
            Console.Write(tt.GetY());
            Console.Write(") - (");
            Console.Write(tt.GetW());
            Console.Write(", ");
            Console.Write(tt.GetH());
            Console.Write(") - ");
            tt.OutText();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Paint app = new Paint();
            app.add(new Circle());
            app.add(new Square());
            app.get(0).move(1, 1);
            app.get(0).size(2, 4);
            app.get(1).move(2, 2);
            app.get(1).size(4, 8);
            
            FigureText ft = new FigureText(new Text("word"));

            ft.draw();
            app.add(ft);
            app.get(2).move(7, 7);

            app.draw();

            /*app->add(new Circle());
            app->add(new Square());*/
        }
    }
}
