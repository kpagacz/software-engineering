using System;
using System.Collections.Generic;
using System.Linq;


namespace lab_2
{
	// PRZYKLAD 1
	/* cos jakby klasa nadrzedna
	 * mechanizm wspierajacy polimorfizm
	 * nie zawiera danych skladowych
	 * zawiera tylko deklaracje metod (zobowiazanie)
	 * nie zawiera implementacji metod
	 * nie zawiera modyfikatorow dostepu - wszystko jest publiczne
	 */
	public interface IOpenable
	{
		bool IsOpen { get; }
		void Open();
		void Close();
	}

	public class C1
    {

    }

	public class C2
    {

    }

	public interface I2
    {

    }

	// Book jest otwieralna (implementuje interfejs IOpenable)
	// Klasa moze dziedziczyc tylko po 1 klasie, ale po wielu interfejsach!!!
	public class Book : C1, I2, IOpenable
	{
		private int page;
		public bool IsOpen 
		{
			get
			{
				if (page > 0)
					return true;
				else
					return false;
			}
		}
		public void Open()
        {
			page = 1;
        }

		public void Close()
        {
			page = 0;
        }
	}

	// PRZYKLAD 2
	abstract class Animal
    {
		protected string name;
		public Animal(string name)
        {
			this.name = name;
        }

        public override string ToString()
        {
			return "Zwierze: " + this.name;
        }
    }

	class Cat: Animal
    {
		public Cat(string name) : base(name)
        {

        }
        public override string ToString()
        {
			return "Cat: " + this.name;
        }
    }

	class Dog: Animal
    {
		public Dog(string name) : base(name)
        {

        }
        public override string ToString()
        {
			return "Dog: " + this.name;
        }
    }

	public class Program
	{
		public static void Main()
		{
			// PRZYKLAD 1
			Console.WriteLine("PRZYKLAD 1");
			Book b = new Book();
			IOpenable i = new Book();
			b.Close();
			i.Close();

			Console.WriteLine(b.IsOpen);
			Console.WriteLine(i.IsOpen);

			// PRZYKLAD 2
			Console.WriteLine("\nPRZYKLAD 2");
			Animal a;
			Cat c;
			Dog d;

			var zoo = new List<Animal>();

			a = new Cat("Mialczek");
			c = new Cat("Mruczek");
			d = new Dog("Reksio");

			zoo.Add(a);
			zoo.Add(c);
			zoo.Add(d);

            // przyklad a wywola metode dla obiektu, a nie dla interfejsu!!!
            // to jest inaczej niz w c++ !!
            // w c++ wywolana bylaby metoda Animal.ToString(), a tu jest Cat.ToString()
            Console.WriteLine(a); // zwraca "Cat: Mialczek"!!!
			Console.WriteLine(c);
			Console.WriteLine(d);

			Console.WriteLine();


			foreach(Animal tmp in zoo)
            {
				// sprawdzanie czy obiekt jest klasa/interfejsem
				if(tmp is Cat)
                {
					Console.WriteLine("To jest Kot");
                }

				// przydatne do rzutowania w dol
				Console.WriteLine(tmp as Animal);
            }
		}


	}
}
