using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PP_8
{
    abstract class DialogDirector {
        public abstract void WidgetChanged(Widget w);
        public abstract void CreateWidgets();
    }

    class Dialog : DialogDirector
    {        
        ListBox listbox = new ListBox();
        TextBox textbox = new TextBox();
        List<Button> button = new List<Button>(); /* 0 - Добавить, 1 - Удалить, 2 - Изменить */

        public void Add(ListBox lb)
        {
            listbox = lb;
        }
        public void Add(TextBox tb)
        {
            textbox = tb;
        }
        public void Add(Button bt)
        {
            button.Add(bt);
        }

        public override void WidgetChanged(Widget w)
        {
            //    if (w == listbox)
            //    {

            //    }
        }
        
        public override void CreateWidgets()
        {
            // if() {} else {}
        }

        public void TextHandler(object o, EventArgs e)
        {
            int flag = -1;
            // проход по всему листобксу и проверка совпадений
            for (int i = 0; i <= listbox.index; i++)
            {
                if (listbox.Get(i) != textbox.Text)
                {
                    flag = 0;
                }
                else {
                    flag = 10;
                    break;
                }
            }
            if (flag <= 0)
            {
                button[1].enabled = false; button[0].enabled = true;
                Console.WriteLine("Кнопка Удалить недоступна \nДоступна кнопка Добавить \n");
                if (listbox.enabled)
                {
                    button[2].enabled = true;
                    Console.WriteLine("Доступна кнопка Изменить \n");
                }
            }
            else {
                Console.WriteLine("Значение в textbox совпадает с одним из значений в listbox \n");
                button[1].enabled = true;
                Console.WriteLine("Доступна кнопка Удалить \n");
            }
        }

        public void SelectHandler(object o, EventArgs e)
        {
            //Console.Write($"Выбранный элемент { listbox.elements } записан в поле textbox\n");
            // кнопка удалить доступна
            button[1].enabled = true;
            Console.WriteLine("Доступна кнопка Удалить \n");
        }

        public void TextHandlerClick(object o, EventArgs e)
        {
            Console.WriteLine("Clicked \n");
        }
    }

    abstract class Widget
    {
        protected DialogDirector director;

        public Widget(DialogDirector d)
        {
            director = d;
        }
        public virtual void Changed()
        {
            //director.WidgetChanged(this);
        }
    }

    class TextBox 
    {
        string text = "";
        public event EventHandler Change;
        
        public string Text
        {
            get { return text; }
            set
            {
                text = value;
                if (Change != null)
                {
                    Console.WriteLine($"textbox = {text}");
                    Change((object)this, EventArgs.Empty);
                }
            }
        }        
    }

    class ListBox : Widget
    {
        public List<string> elements = new List<string>();
        public int index = -1;
        public int selindex = -1;
        TextBox textbox = new TextBox();
        public event EventHandler Select;
        public bool enabled = false;

        public ListBox(DialogDirector d) : base(d) { }

        public void AddItem(string s)
        {
            elements.Add(s);
            index++;
            Console.WriteLine($"Добавлен элемент = {elements[index]} \n");
        }
        public void RemoveItem(int index)
        {
            elements.Remove(elements[index]);
        }
        public void Selected(int index)
        {
            selindex = index;
            Console.Write($"Выбранный элемент {elements[index]}\n");
            if (Select != null)
            {
                Select((object)this, EventArgs.Empty);
            }
        }
        public string Get(int index)
        {
            return elements[index];
        }
        public void CreateWidgets() {
            director.CreateWidgets();
        }
        public override void Changed()
        {
            director.WidgetChanged(this);
        }
    }

    class Button
    {
        string text;
        public event EventHandler clicked;
        public bool enabled = false;
        public string Bt
        {
            get { return text; }
            set
            {
                text = value;
                EventHandler c = clicked;
                if (c != null && enabled == true)
                {
                    c((object)this, EventArgs.Empty);
                    Console.WriteLine($"Была нажата кнопка = {text}");
                }
            }
        }
    }    

    class Program
    {
       static void Main(string[] args)
        {
            //Mediator mediator = new Mediator();
            Dialog dialog = new Dialog();
            ListBox lb = new ListBox();
            TextBox tb = new TextBox();
            Button bt1 = new Button(); Button bt2 = new Button(); Button bt3 = new Button(); Button bt4 = new Button(); Button bt5 = new Button();

            /* Добавление кнопок */
            bt3.Bt = "Добавить";
            dialog.Add(bt3);
            bt4.Bt = "Удалить";
            dialog.Add(bt4);
            bt5.Bt = "Изменить";
            dialog.Add(bt5);
                       
            tb.Change += (EventHandler)dialog.TextHandler;
            //mediator.ChangedTextBox(dialog, tb);
            dialog.Add(tb);

            /* Добавление ListBox */
            lb.Select += (EventHandler)dialog.SelectHandler;
            //mediator.SelectedItem(dialog, lb);
            dialog.Add(lb);   

            /* Добавление элементов в ListBox */
            //tb.Text = "123"; // запись в textbox значения Элемент1
            lb.AddItem("123");           

            //tb.Text = "234"; // запись в textbox значения Элемент2
            lb.AddItem("234");
            //Console.WriteLine($"textbox = {tb.Text}");        

            lb.AddItem("345");      
            
            // запись значения из textbox в listbox
            tb.Text = "123";

            // выбираем значение в listbox
            lb.Selected(1);

            return;
        }
    }

    /* 0 - OK; 1 - Отмена; 2 - Добавить; 3 - Удалить; 4 - Изменить */
    //bt1.Bt = "ОК";
    //dialog.Add(bt1);
    //bt2.Bt = "Отмена";
    //dialog.Add(bt2);

    //bt1.clicked += (EventHandler)dialog.TextHandlerClick; // нажатие
}
