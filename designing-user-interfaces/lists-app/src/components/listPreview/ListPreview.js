import React from "react";
import ListElement from "../listElement/ListElement";
import styles from "./ListPreview.module.css";

const ListPreview = ({ list, onclickHandler }) => {
  return (
    <div className={styles["list-preview-container"]} onClick={onclickHandler}>
      <div className={styles["list-preview"]}>
        <div className={styles["glass-overlay"]} />
        <div className={styles["items-container"]}>
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
      </div>
      <div className={styles["list-description-container"]}>
        <span className={styles["label"]}>{list.title}</span>
        <span className={styles.date}>Created at: {list.formatDate()}</span>
      </div>
    </div>
  );
};

export default ListPreview;
