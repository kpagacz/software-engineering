class ToDoList {
  items = [];
  checked = [];
  title = "List Title";
  createdAt = null;
  archived = false;
  archivedAt = null;

  constructor(
    items = [],
    checked = [],
    title = "List Title",
    archived = false
  ) {
    this.items = items;
    this.checked = checked;
    this.title = title;
    this.createdAt = new Date();
    this.archived = archived;
    this.archivedAt = null;
  }

  formatDate() {
    return (
      String(this.createdAt.getDate()).padStart(2, "0") +
      "-" +
      String(this.createdAt.getMonth() + 1).padStart(2, "0") +
      "-" +
      this.createdAt.getFullYear() +
      " " +
      String(this.createdAt.getHours()).padStart(2, "0") +
      ":" +
      String(this.createdAt.getMinutes()).padStart(2, "0")
    );
  }

  formatArchivedAt() {
    return (
      String(this.archivedAt.getDate()).padStart(2, "0") +
      "-" +
      String(this.archivedAt.getMonth() + 1).padStart(2, "0") +
      "-" +
      this.archivedAt.getFullYear() +
      " " +
      String(this.archivedAt.getHours()).padStart(2, "0") +
      ":" +
      String(this.archivedAt.getMinutes()).padStart(2, "0")
    );
  }
}

export default ToDoList;
