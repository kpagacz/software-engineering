import React from "react";
import Navbar from "../../components/navbar/Navbar";
import styles from "./SettingsView.module.css";

const SettingsView = () => {
  return (
    <div className={styles["settings-container"]}>
      <Navbar />
      <div>Settings</div>
    </div>
  );
}

export default SettingsView;
