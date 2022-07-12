#include <iostream>
#include<vector>

using namespace std;

namespace ECommerce {
	namespace Database {
		class Guest {
			string _fullname;
			string _connected_date; //tarix saat

			Guest(string fullname, string connected_date) {
				setFullname(fullname);
				setconnecteddate(connected_date);
			}

			void setFullname(string fullname)
			{
				if (fullname.length() < 3)
					throw"wrong length fullname";
				else
					_fullname = fullname;
			}

			void setconnecteddate(string connected_date) {
				_connected_date = connected_date;
			}

			string get_fullname() { return _fullname; }
			string get_date() { return _connected_date; }

			void print() {
				cout << "fullname:" << get_fullname() << endl;
				cout << "data:" << get_date() << endl;
			}
		};

		class Admin {
			string _username;
			string _password;

		public:
			Admin() = default;
			
			Admin(string username, string password) {
				set_username(username);
				set_password(password);
			}

			void set_username(string username) {
				if (username.length() < 3)
					throw"wrong length fullname";
				else
					_username = username;
			}

			void set_password(string password) {
				if (password.length() < 3)
					throw"wrong length fullname";
				else
					_password = password;
			}

			string get_username() { return _username; }
			string get_password() { return _password; }

			void print() {
				cout << "username:" << get_username() << endl;
				cout << "password:" << get_password() << endl;
			}
		};

		class Product {
			int _id; //avtomatik
			string _name;
			string _description;
			double _price;
			double _discount;
			double _tax; //vergi faizi

			int staticid = 1;

		public:

			Product() = default;
			Product(int id, string name, string description, double price, double discount, double tax) {
				set_id(id);
				set_name(name);
				set_description(description);
				set_price(price);
				set_discount(discount);
				set_tax(tax);
			}

			void set_id(int id) {
				if (id < 0)
					throw"wrong id";
				else
					_id = id;
			}

			void set_name(string name) {
				if (name.length() < 0)
					throw"wrong name";
				else
					_name = name;
			}

			void set_description(string description) {
				if (description.length() < 0)
					throw"wrong description";
				else
					_description = description;
			}

			void set_price(double price) {
				if (price < 0)
					throw"wrong price";
				else
					_price = price;
			}

			void set_discount(double discount) {
				_discount = discount;
			}

			void set_tax(double tax) {
				_tax = tax;
			}



			int get_id() { return _id; }
			string get_name() { return _name; }
			string get_description() { return _description; }
			double get_price() { return _price; }
			double get_discount() { return _discount; }
			double get_tax() { return _tax; }

			void print() {
				cout << "id:" << get_id() << endl;
				cout << "name:" << get_name() << endl;
				cout << "description:" << _description << endl;
				cout << "price:" << get_price() << endl;
				cout << "discount:" << _discount << endl;
				cout << "tax" << get_tax() << endl;
			}
		};

		

		class Databases {
		public:
			vector<Product>products;
			vector<Admin>admins;
			vector<Guest>guest;
		};

	}

	void start() {
		using namespace Database;
		Databases database;
		//product

		//Product product(2,"banan", "nyam nyam", 12, 2, 32);
		//database.products.push_back(product);


		//admin add

		Admin admin("Niko", "niko123");
		database.admins.push_back(admin);
		
		for (int i = 0; i < database.admins.size(); i++) {
			database.admins[i].print();
		}
	}
}

int main()
{
	ECommerce::start();
}
