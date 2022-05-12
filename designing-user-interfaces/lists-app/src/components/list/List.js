import React, { createRef } from "react";
import { useState } from "react";
import ListElement from "../listElement/ListElement";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import { faArrowRight } from "@fortawesome/free-solid-svg-icons";
import { CSSTransition, TransitionGroup } from "react-transition-group";
import styles from "./List.module.css";

const List = () => {
  const [checked, setChecked] = useState([]);
  const [texts, setTexts] = useState([]);

  const onCheckboxChangeHandler = (index) => {
    return () => {
      setChecked(updateList(checked, index, !checked[index]));
    };
  };

  const updateList = (list, index, value) => {
    const copy = [...list];
    copy[index] = value;
    return copy;
  };

  const onTextChangeHandler = (index) => {
    return (event) => {
      setTexts(updateList(texts, index, event.target.value));
    };
  };

  const newListHandler = (event) => {
    event.preventDefault();
    setChecked([...checked, false]);
    setTexts([...texts, event.target[0].value]);
    event.target[0].value = "";
  };

  const getItemsToDo = () => {
    let checkedCopy = [...checked];
    return (
      <TransitionGroup>
        {checkedCopy.reverse().map((check, index) => {
          if (!check) {
            let reverse_index = checked.length - 1 - index;
            const textHandler = onTextChangeHandler(reverse_index);
            const checkboxHandler = onCheckboxChangeHandler(reverse_index);

            const itemRef = createRef();
            return (
              <CSSTransition
                key={reverse_index}
                timeout={500}
                classNames={{
                  enterDone: styles["todo-item-enter-active"],
                  enterActive: styles["todo-item-enter"],
                  exitActive: styles["todo-item-exit-active"],
                  exitDone: styles["todo-item-exit"],
                }}
                nodeRef={itemRef}
              >
                <div ref={itemRef}>
                  <ListElement
                    onTextChange={textHandler}
                    onCheckboxChange={checkboxHandler}
                    checked={check}
                    text={texts[reverse_index]}
                    key={reverse_index}
                  />
                </div>
              </CSSTransition>
            );
          } else return null;
        })}
      </TransitionGroup>
    );
  };

  const getDoneItems = () => {
    let checkedCopy = [...checked];
    return (
      <TransitionGroup>
        {checkedCopy.reverse().map((check, index) => {
          if (check) {
            let reverse_index = checked.length - 1 - index;
            const textHandler = onTextChangeHandler(reverse_index);
            const checkboxHandler = onCheckboxChangeHandler(reverse_index);

            const itemRef = createRef();

            return (
              <CSSTransition
                key={reverse_index}
                timeout={500}
                classNames={{
                  enterDone: styles["done-item-enter-active"],
                  enterActive: styles["done-item-enter"],
                  exitActive: styles["done-item-exit-active"],
                  exitDone: styles["done-item-exit"],
                }}
                nodeRef={itemRef}
              >
                <div ref={itemRef}>
                  <ListElement
                    onTextChange={textHandler}
                    onCheckboxChange={checkboxHandler}
                    checked={check}
                    text={texts[reverse_index]}
                    key={reverse_index}
                    readOnly="readonly"
                  />
                </div>
              </CSSTransition>
            );
          } else return null;
        })}
      </TransitionGroup>
    );
  };

  return (
    <div>
      <div className={styles["items-container"]}>
        <div className="todo-container">
          <div>To Do:</div>
          <form onSubmit={newListHandler}>
            <input
              type="text"
              placeholder="Add another item..."
              autoFocus
              required="required"
            ></input>
            <button type="submit">
              <FontAwesomeIcon icon={faArrowRight} />
            </button>
          </form>
          {getItemsToDo()}
        </div>
        <div className="done-container">
          <div>Done:</div>
          {getDoneItems()}
        </div>
      </div>
    </div>
  );
};

export default List;
