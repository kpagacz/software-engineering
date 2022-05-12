import React from "react";
import styles from "./ArchiveView.module.css";
import Navbar from "../../components/navbar/Navbar";

const ArchiveView = () => {
  return <div className={styles["archive-container"]}>
    <Navbar />
    <div>Archived content</div>
  </div>
}

export default ArchiveView;
