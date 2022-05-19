class ToDoList {
  items = [];
  checked = [];

  constructor(items = [], checked = []) {
    this.items = items;
    this.checked = checked;
  }
}

export default ToDoList;
