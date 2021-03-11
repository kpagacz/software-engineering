using System;
using System.Collections.Generic;


namespace myNamespace
{
	public class Program
	{
		public static void Main()
		{
			// Wszystkie klasy customowe mają semantykę referencji
			Person p, q;
			p = new Person();
			q = new Person();
			p.Name = "Ala";
			q = p;
			q.Name = "Tomek";
			Console.WriteLine("p.Name = " + p.Name + "!");
			Console.WriteLine("q.Name = " + q.Name + "!");

			// Wszystkie typy mają semantykę wartości
			int x, y;
			x = 5;
			y = x;
			y = 7;
			Console.WriteLine("x=" + x.ToString());
			Console.WriteLine("y=" + y.ToString());

			// Tablice
			int[] tab = new int[10];
			for (int i = 0; i < 10; i++)
			{
				tab[i] = 2 * i;
			}

			for (int i = 0; i < 10; i++)
			{
				System.Console.WriteLine(tab[i]);
			}

			// Tablice referencji!
			Person[] grupa = new Person[10];
			for (int i = 0; i < 10; i++)
			{
				grupa[i] = new Person();
				grupa[i].Name = "Imie" + i.ToString();
				grupa[i].LastName = "Nazwisko" + i.ToString();
			}

			for (int i = 0; i < 10; i++)
			{
				System.Console.WriteLine(grupa[i]);
			}

			// Listy
			// uwaga na przechowywanie referencji
			List<Person> grupa2 = new List<Person>();
			grupa2.Add(new Person());
			Person ala = new Person()
			{
				Name = "Ala",
				LastName = "Judzik"
			};
			grupa2.Add(ala);

			foreach (Person person in grupa2)
			{
				System.Console.WriteLine(person);
			}

			grupa2.RemoveAt(0);
			foreach (Person person in grupa2)
			{
				System.Console.WriteLine(person);
			}

			// Slownik
			Dictionary<int, Person> slownik = new Dictionary<int, Person>();
			slownik.Add(1, new Person() { Name = "Konrad", LastName = "Pagacz" });
			slownik.Add(2, new Person() { Name = "Marysia", LastName = "Malysa" });

			foreach (var key in slownik.Keys)
			{
				System.Console.WriteLine(key + " >> " + slownik[key]);
			}

			slownik.Remove(1);

		}
	}

	public class Person
	{
		private string name;
		public string Name
		{ // property, preferowane ponad set get
			get
			{
				return this.name;
			}
			set
			{
				this.name = value;
			}
		}

		public string LastName
		{
			set;
			get;
		}

		public int NameLenth
		{
			get
			{
				return name.Length; // length nie jest metoda!
			}
		}

		public override string ToString()
		{
			return this.name + " " + this.LastName;
		}
	}
}
