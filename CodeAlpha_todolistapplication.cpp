#include<iostream>
#include<string>
using namespace std;
class Task{
private:
    string name;
    bool completed;

public:
    Task() : name(""), completed(false) {}
    Task(string name) : name(name), completed(false) {}

    string getName() const{
		 return name; 
		 }		 
    bool isCompleted() const{ 
		return completed; 
		}

    void markCompleted(){ 
		completed = true; 
	}
};
class ToDoList{
private:
    Task* tasks;
    int taskCount;
    int capacity;
public:
    ToDoList() : taskCount(0), capacity(1) { tasks = new Task[capacity]; }
    ~ToDoList(){
		delete[] tasks; 
	}

    void addTask(string name){
        if (taskCount==capacity){
            capacity *=2;
            Task* newTasks=new Task[capacity];
            for (int i=0;i<taskCount;++i){
                newTasks[i]=tasks[i];
            }
            delete[] tasks;
            tasks=newTasks;
        }
        tasks[taskCount]=Task(name);
        taskCount++;
    }

    void markTaskCompleted(int taskNumber){
        if(taskNumber>=1&&taskNumber<=taskCount){
            tasks[taskNumber - 1].markCompleted();
        }
    }

    void displayTasks(){
        for (int i = 0; i < taskCount; ++i) {
            cout<<i + 1<<". "<<tasks[i].getName()<<" ("<<(tasks[i].isCompleted() ? "Completed" : "Pending")<<")"<<endl;
        }
    }
};
int main(){
    ToDoList toDoList;

    int choice;
    do{
        cout<<"---------- To-Do List Menu -----------"<<endl;
        cout<<"1. Add Task"<<endl;
        cout<<"2. Mark Task as Completed"<<endl;
        cout<<"3. Display Tasks"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"-----------------------------------------"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1:{
                string name;
                cout<<"Enter task name: ";
                cin.ignore();
                getline(cin, name);
                toDoList.addTask(name);
                break;
            }
            case 2:{
                int taskNumber;
                cout<<"Enter the task number to mark as completed: ";
                cin>>taskNumber;
                toDoList.markTaskCompleted(taskNumber);
                break;
            }
            case 3:
                toDoList.displayTasks();
                break;
            case 4:
                cout<<"Exiting program. Bye!"<<endl;
                break;
            default:
                cout<<"Invalid choice.Please try again!"<<endl;
        }
    } while (choice != 4);
    return 0;
}
