class ToDoList {
  items = [];
  checked = [];
  title = "List Title";

  constructor(items = [], checked = [], title = "List Title") {
    this.items = items;
    this.checked = checked;
    this.title = title;
  }
}

export default ToDoList;
