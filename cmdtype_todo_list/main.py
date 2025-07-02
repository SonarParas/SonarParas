# define an empty list to hold our tasks
tasks = []

# define a function to display the current tasks
def show_tasks():
    print("Current Tasks:")
    if len(tasks) == 0:
        print("No tasks yet!")
    else:
        for i, task in enumerate(tasks):
            print(f"{i+1}. {task}")

# define a function to add a task
def add_task():
    task = input("Enter a task: ")
    tasks.append(task)
    print(f"Added task '{task}'")
    show_tasks()

# define a function to remove a task
def remove_task():
    show_tasks()
    if len(tasks) == 0:
        return
    task_index = int(input("Enter the number of the task to remove: ")) - 1
    task = tasks.pop(task_index)
    print(f"Removed task '{task}'")
    show_tasks()

# define a function to quit the application
def quit_app():
    print("Goodbye!")
    quit()

# main loop of the application
while True:
    print("What would you like to do?")
    print("1. Show tasks")
    print("2. Add a task")
    print("3. Remove a task")
    print("4. Quit")
    choice = input("Enter the number of your choice: ")
    if choice == "1":
        show_tasks()
    elif choice == "2":
        add_task()
    elif choice == "3":
        remove_task()
    elif choice == "4":
        quit_app()
    else:
        print("Invalid choice, please try again.")
