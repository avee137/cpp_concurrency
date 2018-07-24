#include<iostream>
#include<thread>

using namespace std;

/*
void do_some_work();
std::thread my_thread(do_some_work);
*/

class background_task
{
	public:
		void operator()()const
		{
			do_something();
			do_something_else();
		}
		void do_something() const;
		void do_something_else() const;

};

void background_task::do_something() const
{
	cout << "do something" << endl;
}

void background_task::do_something_else() const
{
	cout << "do something else" << endl;
}

int main()
{
	background_task f;
	std::thread my_thread(f);
	/*join wait for thread to complete*/
	//my_thread.join();
	/*detach let thread execute on its own*/
	my_thread.detach();
	return 0;
}
