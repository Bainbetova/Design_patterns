using System;
using System.Collections.Generic;

namespace task8
{
    class TextBox
    {
        private string text;
        public string Text
        {
            get
            {
                return text;
            }
            set
            {
                text = value;
                OnTextChanged(null);
            }
        }

        protected virtual void OnTextChanged(EventArgs e)
        {
            TextChanged?.Invoke(this, e);
        }

        public event EventHandler TextChanged;
    }

    class Item
    {
        public string Text { get; set; }

        public Item(string text)
        {
            Text = text;
        }
    }

    class ListBox
    {
        List<Item> items = new List<Item>();
        int selectedIndex = -1;

        public Item Selected
        {
            get
            {
                if (selectedIndex >= 0)
                {
                    return items[selectedIndex];
                }
                else
                {
                    throw new Exception("Nothing selected");
                }
            }
        }

        public void AddItem(string item)
        {
            items.Add(new Item(item));
        }

        public void RemoveItem()
        {
            items.RemoveAt(selectedIndex);
        }

        public void Select(int index)
        {
            if (Check(index))
            {
                selectedIndex = index;
                OnIndexChanged(null);
            }
        }

        bool Check(int index)
        {
            if (index >= 0 && index < items.Count)
            {
                return true;
            }

            throw new Exception("Index out of range");
        }

        protected virtual void OnIndexChanged(EventArgs e)
        {
            IndexChanged?.Invoke(this, e);
        }

        public event EventHandler IndexChanged;
    }

    class Button
    {
        public string Text { get; set; }

        public Button(string text)
        {
            Text = text;
        }

        public void Click()
        {
            OnClicked(null);
        }

        protected virtual void OnClicked(EventArgs e)
        {
            Clicked?.Invoke(this, e);
        }

        public event EventHandler Clicked;
    }
    class Dialog
    {
        List<TextBox> ltb = new List<TextBox>();
        List<ListBox> llb = new List<ListBox>();
        List<Button> lb = new List<Button>();

        public void AddContol(TextBox tb)
        {
            ltb.Add(tb);
        }

        public void AddContol(ListBox lb)
        {
            llb.Add(lb);
        }

        public void AddContol(Button b)
        {
            lb.Add(b);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Dialog dialog = new Dialog();

            TextBox field = new TextBox();
            field.TextChanged += (object sender, EventArgs e) =>
            {
                Console.WriteLine("New value entered: " + field.Text);
            };
            dialog.AddContol(field);

            ListBox listBox = new ListBox();
            listBox.IndexChanged += (object sender, EventArgs e) =>
            {
                Console.WriteLine("Another item selected: "
                    + listBox.Selected.Text);
            };
            dialog.AddContol(listBox);

            Button ok = new Button("OK");
            ok.Clicked += (object sender, EventArgs e) =>
            {
                Console.WriteLine("The button OK was clicked");
            };
            dialog.AddContol(ok);

            Button cancel = new Button("Cancel");
            cancel.Clicked += (object sender, EventArgs e) =>
            {
                Console.WriteLine("The button Cancel was clicked");
            };
            dialog.AddContol(cancel);

            Button add = new Button("Add");
            add.Clicked += (object sender, EventArgs e) =>
            {
                Console.WriteLine("The button Add was clicked");
                listBox.AddItem(field.Text);
            };
            dialog.AddContol(add);

            Button remove = new Button("Remove");
            remove.Clicked += (object sender, EventArgs e) =>
            {
                Console.WriteLine("The button Remove was clicked");
                listBox.RemoveItem();
            };
            dialog.AddContol(remove);

            Button edit = new Button("Edit");
            edit.Clicked += (object sender, EventArgs e) =>
            {
                Console.WriteLine("The button Edit was clicked");
                listBox.Selected.Text = field.Text;
            };
            dialog.AddContol(edit);

            field.Text = "Item1";
            add.Click();

            listBox.Select(0);
            field.Text = "Item11";
            edit.Click();
            
            remove.Click();

            Console.ReadKey(); // Debug
        }
    }
}
