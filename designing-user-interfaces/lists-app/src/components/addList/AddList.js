import { faPlusCircle } from "@fortawesome/free-solid-svg-icons";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import React from "react";
import ToDoList from "../../models/ToDoList";
import styles from "./AddList.module.css";

const AddList = ({ addList }) => {
  const onSubmitNewListHandler = (event) => {
    event.preventDefault();
    const list = new ToDoList([event.target[0].value], [false]);
    event.target[0].value = "";
    addList(list);
  };

  const onButtonClickHandler = (event) => {
    event.preventDefault();
    addList(new ToDoList());
  };

  return (
    <div className={styles["add-list-container"]}>
      <form onSubmit={onSubmitNewListHandler}>
        <input type="text" placeholder="Start your list here..." autoFocus required/>
      </form>
      <p>...or click...</p>
      <button onClick={onButtonClickHandler}>
        <FontAwesomeIcon icon={faPlusCircle} />
      </button>
    </div>
  );
};

export default AddList;
