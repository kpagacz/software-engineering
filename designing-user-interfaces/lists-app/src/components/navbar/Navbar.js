import React from "react";
import styles from "./Navbar.module.css";

const Navbar = () => {
  return (
    <nav className={styles.navbar}>
      Navigation
      <div>Home</div>
      <div>Settings</div>
    </nav>
  );
};

export default Navbar;
