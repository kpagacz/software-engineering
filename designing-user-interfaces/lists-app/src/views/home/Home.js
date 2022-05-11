import React from "react";
import Navbar from "../../components/navbar/Navbar";
import styles from "./Home.module.css";

const Home = () => {
  return (
    <div className={styles["home-container"]}>
      <div>
        <Navbar />
      </div>
      <div className={styles["lists-preview"]}>
        <div>ListPreview</div>
        <div>ListPreview</div>
        <div>ListPreview</div>
        <div>ListPreview</div>
        <div>ListPreview</div>
        <div>ListPreview</div>
        <div>ListPreview</div>
      </div>
    </div>
  );
};

export default Home;
