import React from "react";
import styles from "./Navbar.module.css";
import { Link } from "react-router-dom";



const Navbar = () => {
  return (
    <nav className={styles.navbar}>
      <div>
        <Link to="/" className={styles.navlink}>Home</Link>
      </div>
      <div>
        <Link to="/archive" className={styles.navlink}>Archived</Link>
      </div>
      <div>
        <Link to="/settings" className={styles.navlink}>Settings</Link>
      </div>
    </nav>
  );
};

export default Navbar;
