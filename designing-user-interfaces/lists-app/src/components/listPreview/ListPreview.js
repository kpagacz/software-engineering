import React from "react";
import ListElement from "../listElement/ListElement";
import styles from "./ListPreview.module.css";

const ListPreview = ({ list, onclickHandler }) => {
  return (
    <div className={styles["list-preview-container"]}>
      <div onClick={onclickHandler} className={styles["list-preview"]}>
        {list.items.map((item, index) => {
          return (
            <ListElement
              checked={list.checked[index]}
              text={item}
              readOnly={true}
            />
          );
        })}
      </div>
      List preview. Elements no: {list.items.length}
    </div>
  );
};

export default ListPreview;
