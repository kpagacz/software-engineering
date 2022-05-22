import React from "react";
import ListElement from "../listElement/ListElement";
import styles from "./ListPreview.module.css";

const ListPreview = ({ list, onclickHandler }) => {
  return (
    <div className={styles["list-preview-container"]} onClick={onclickHandler}>
      <div className={styles["list-preview"]}>
        <div className={styles["glass-overlay"]}></div>
        {list.items.map((item, index) => {
          return (
            <ListElement
              checked={list.checked[index]}
              key={index}
              text={item}
              readOnly={true}
            />
          );
        })}
      </div>
      <div className={styles["label"]}>
        {list.title}
      </div>
    </div>
  );
};

export default ListPreview;
