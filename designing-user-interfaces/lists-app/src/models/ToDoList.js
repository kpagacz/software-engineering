class ToDoList {
  todoItems = [];
  doneItems = [];

  constructor() {}

  addItem(item) {
    this.todoItems = [...this.todoItems, item];
  }
}

export default ToDoList;
