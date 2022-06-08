import React from "react";
import styles from "./ConfirmationModal.module.css";

const ConfirmationModal = ({ prompt, onConfirmation, onRefusal, showFlag }) => {
  if (!showFlag) return null;

  return (
    <div className={styles["modal-container"]}>
      <div className={styles["confirmation-box"]}>
        <h5>{prompt}</h5>
        <div className={styles.buttons}>
          <button onClick={onConfirmation} className={styles["confirm-button"]}>
            Delete
          </button>
          <button onClick={onRefusal} className={styles["cancel-button"]}>
            Cancel
          </button>
        </div>
      </div>
    </div>
  );
};

export default ConfirmationModal;
