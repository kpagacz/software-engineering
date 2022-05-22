import React, { createRef } from "react";
import ListElement from "../listElement/ListElement";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import { faArrowRight } from "@fortawesome/free-solid-svg-icons";
import { CSSTransition, TransitionGroup } from "react-transition-group";
import styles from "./List.module.css";

const List = ({ list, index, updateList }) => {
  const onCheckboxChangeHandler = (id) => {
    return () => {
      list.checked[id] = !list.checked[id];
      updateList(list, index);
    };
  };

  const onTextChangeHandler = (id) => {
    return (event) => {
      list.items[id] = event.target.innerText;
      updateList(list, index);
    };
  };

  const newListElementHandler = (event) => {
    event.preventDefault();
    list.checked = [...list.checked, false];
    list.items = [...list.items, event.target[0].value];
    event.target[0].value = "";
    updateList(list, index);
  };

  const getItemsToDo = () => {
    let checkedCopy = [...list.checked];
    return (
      <TransitionGroup component={null}>
        {checkedCopy.reverse().map((check, index) => {
          if (!check) {
            let reverse_index = list.checked.length - 1 - index;
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
                    text={list.items[reverse_index]}
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
    let checkedCopy = [...list.checked];
    return (
      <TransitionGroup component={null}>
        {checkedCopy.reverse().map((check, index) => {
          if (check) {
            let reverse_index = list.checked.length - 1 - index;
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
                    text={list.items[reverse_index]}
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
        <div className={styles["todo-container"]}>
          <form onSubmit={newListElementHandler}>
            <input
              type="text"
              placeholder="Add another item..."
              autoFocus
              required="required"
            ></input>
            <button type="submit" className={styles["new-list-element-button"]}>
              <FontAwesomeIcon icon={faArrowRight} />
            </button>
          </form>
          {getItemsToDo()}
        </div>
        <div className={styles["todo-container"]}>
          {getDoneItems()}
        </div>
      </div>
    </div>
  );
};

export default List;
