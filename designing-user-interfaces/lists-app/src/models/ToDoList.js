class ToDoList {
  items = [];
  checked = [];
  title = "List Title";
  createdAt = null;
  archived = false;

  constructor(items = [], checked = [], title = "List Title") {
    this.items = items;
    this.checked = checked;
    this.title = title;
    this.createdAt = new Date();
  }

  formatDate() {
    return (
      (String)(this.createdAt.getDate()).padStart(2, "0") +
      "-" +
      (String)(this.createdAt.getMonth() + 1).padStart(2, "0") +
      "-" +
      this.createdAt.getFullYear() +
      " " +
      String(this.createdAt.getHours()).padStart(2, "0") +
      ":" +
      String(this.createdAt.getMinutes()).padStart(2, "0")
    );
  }
}

export default ToDoList;
