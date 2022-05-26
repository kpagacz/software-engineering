import React, { useEffect, useRef } from "react";
import styles from "./ListTitle.module.css";

const ListTitle = ({ list, index, updateList }) => {
  const titleDiv = useRef(null);

  useEffect(() => {
    titleDiv.current.innerText = list.title;
  }, []);

  const onTitleChangeHandler = (event) => {
    list.title = event.target.innerText;
    updateList(list, index);
  };

  return (
    <div
      ref={titleDiv}
      onInput={onTitleChangeHandler}
      contentEditable={true}
      suppressContentEditableWarning={true}
      className={styles["list-title"]}
    ></div>
  );
};

export default ListTitle;
