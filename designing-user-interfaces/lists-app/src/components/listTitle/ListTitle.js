import { faBox, faTrash } from "@fortawesome/free-solid-svg-icons";
import { FontAwesomeIcon } from "@fortawesome/react-fontawesome";
import React, { useEffect, useRef, useState } from "react";
import { useNavigate } from "react-router-dom";
import ConfirmationModal from "../confirmationModal/ConfirmationModal";
import styles from "./ListTitle.module.css";

const ListTitle = ({ list, index, updateList, archiveList, deleteList }) => {
  const titleDiv = useRef(null);
  const navigate = useNavigate();
  const [showModal, setShowModal] = useState(false);

  useEffect(() => {
    titleDiv.current.innerText = list.title;
  }, []);

  const onTitleChangeHandler = (event) => {
    console.log("Title change handler launched");
    list.title = event.target.innerText;
    updateList(list, index);
  };

  const handleArchiveClick = (event) => {
    event.preventDefault();
    archiveList(list);
    navigate("/");
  };

  const handleDeleteClick = () => {
    setShowModal(true);
    // deleteList(list);
    // navigate("/");
  };

  return (
    <div className={styles["title-container"]}>
      <div
        ref={titleDiv}
        onInput={onTitleChangeHandler}
        contentEditable={true}
        suppressContentEditableWarning={true}
        className={styles["list-title"]}
      ></div>
      <button
        className={styles["button"]}
        title="Archive this list"
        onClick={handleArchiveClick}
      >
        <FontAwesomeIcon icon={faBox} />
      </button>
      <button
        className={styles["button"]}
        title="Delete this list"
        onClick={handleDeleteClick}
      >
        <FontAwesomeIcon icon={faTrash} />
      </button>
      <ConfirmationModal
        prompt="Are you sure you want to delete this list? (This action is irreversible)."
        showFlag={showModal}
        onConfirmation={() => {
          setShowModal(false);
          deleteList(list);
          navigate("/");
        }}
        onRefusal={() => setShowModal(false)}
      />
    </div>
  );
};

export default ListTitle;
