#include<iostream>
#include <conio.h>
#include<vector>
using namespace std;

void createMenu();
class Task
{
private:
	static vector<Task*> tasks;
	string name;
	string description;
	string executionTerm;
	string responsible;
public:
	Task();
	static vector<Task*>& getTasks()
	{
		return tasks;
	}
	static Task getTaskFromVector(int number)
	{
		Task taskFromVector;
		number--;
		taskFromVector.getTasks()[number];
		return taskFromVector;
	}
	
	void createTask(Task* newTask)
	{
		string infoForField;
		createMenu();
		for (int i = 1; i < 4; i++)
		{
			cin >> infoForField;
			newTask->editTask(infoForField, i);
			tasks.push_back(newTask);
		}
	}
	void editTask(string info,int numberOfField)
	{
		switch (numberOfField)
		{
		case 1:
			setName(info);
			break;
		case 2:
			setDescription(info);
			break;
		case 3:
			setExecutionTerm(info);
			break;
		case 4:
			setResponsible(info);
			break;
		default:
			break;
		}
	}
	string getName()
	{
		return name;
	}
	void removeTask()
	{
		delete this;
	}
	void setName(string _name) 
	{
		name = _name;
	}
	void setDescription(string _description)
	{
		description = _description;
	}
	void setExecutionTerm(string _executionTerm)
	{
		executionTerm = _executionTerm;
	}
	void setResponsible(string _responsible)
	{
		responsible = _responsible;
	}
	static void showAllTasks()
	{
		for (Task* task : tasks)
		{
			cout << task->getName() << endl;
		}
	}
};

void menu()
{
	cout << "1-Create task" << endl;
	cout << "2-Edit task" << endl;
	cout << "3-Remove task" << endl;
	cout << "4-Show all tasks" << endl;
	cout << "ESC-exit"<<endl;
}
void editMenu()
{
	cout << "1-Edit name" << endl;
	cout << "2-Edit description" << endl;
	cout << "3-Edit execution term" << endl;
	cout << "4-Edit responsible for task" << endl;
	cout << "Please enter the number of field and new text" << endl;
}
void createMenu()
{
	cout << "1-Name" << endl;
	cout << "2-Description" << endl;
	cout << "3-Execution term" << endl;
	cout << "4-Responsible for task" << endl;
}
int main()
{
	char c;
	int numberOfTaskForEdit,numberOfFieldForEdit,numberOfTaskForRemoving;
	string infoForEdit;
	Task newTask, taskForEdit;
	
		do
		{
			menu();
			c = _getch();
			switch (c)
			{
			case 1:
				
				newTask.createTask(&newTask);
				break;
			case 2:
				
				cout << "Chose task for edit"<<endl;
				cin >> numberOfTaskForEdit;
				taskForEdit = Task::getTaskFromVector(numberOfTaskForEdit);
				do
				{
					editMenu();
					cin >> numberOfFieldForEdit;
					cin >> infoForEdit;
					taskForEdit.editTask(infoForEdit, numberOfFieldForEdit);
				} while (numberOfFieldForEdit < 0 || numberOfFieldForEdit>4);
				break;

			case 3:
				cout << "Chose task for removing" << endl;
				cin >> numberOfTaskForRemoving;
				Task::getTaskFromVector(numberOfTaskForEdit).removeTask();
				break;
			case 4:
				Task::showAllTasks();
				default:
					break;
			}

		} while (c != 27);
		
	
	return 0;
}