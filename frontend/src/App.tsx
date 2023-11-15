import { FileDoneOutlined } from "@ant-design/icons";
import { Tag } from "antd";
import classNames from "classnames";

import CppUndeads from "../undeads_cpp.json";
import RustUndeads from "../undeads_rust.json";
import styles from "./App.module.scss";

interface Item {
  id: number;
  difficulty: "Easy" | "Medium" | "Hard";
  topic: "Algorithm" | "DataBase";
  title: string;
  description: string;
  labels: string[];
  solutions: string[];
  lang: "Rust" | "C++";
}

// @ts-ignore
const items: Item[] = RustUndeads.map((item) => ({ lang: "Rust", ...item }))
  .concat(CppUndeads.map((item) => ({ lang: "C++", ...item })))
  .sort((a, b) => a.id - b.id);

const RustBase =
  "https://github.com/SKTT1Ryze/Valhalla/blob/main/leetcode-rs/src/solutions/";
const CppBase = "https://github.com/SKTT1Ryze/Valhalla/blob/main/leetcode-cc/";

function App() {
  return (
    <div className={styles.container}>
      <div
        className={styles.title}
        style={
          {
            "--title-margin-top": `${
              items.length * 2.5 - window.innerHeight / 16 / 1.5
            }rem`,
          } as any
        }
      >
        Valhalla
      </div>
      <div className={styles.subtitle}>
        Valhalla of coder, collections of solutions of LeetCode problems.
      </div>
      <div className={styles.langs}>
        <a>
          <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/rust/rust-plain.svg" />
        </a>
        <a>
          <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/cplusplus/cplusplus-original.svg" />
        </a>
      </div>
      <div className={styles["items-header"]}>
        <div style={{ flex: 0.5, position: "relative", left: "1rem" }}>ID</div>
        <div style={{ flex: 4 }}>Title</div>
        <div style={{ flex: 1 }}>Solution</div>
        <div style={{ flex: 1 }}>Difficulty</div>
        <div style={{ flex: 1 }}>Topic</div>
        <div style={{ flex: 2 }}>Labels</div>
      </div>
      <div className={styles["items-container"]}>
        {items.map((item, key) => (
          <div
            key={key}
            className={classNames(styles.item, {
              [styles["item-double"]]: key % 2 !== 0,
            })}
          >
            <div className={styles.id}>{item.id}</div>
            <div className={styles["problem-title"]}>{item.title}</div>
            <div className={styles.solution}>
              {item.solutions.map((solution) => (
                <a
                  href={(item.lang === "Rust" ? RustBase : CppBase) + solution}
                >
                  <FileDoneOutlined
                    style={{ color: item.lang === "Rust" ? "orange" : "blue" }}
                  />
                </a>
              ))}
            </div>
            <div
              className={classNames(styles["problem-difficulty"], {
                [styles.easy]: item.difficulty === "Easy",
                [styles.medium]: item.difficulty === "Medium",
                [styles.hard]: item.difficulty === "Hard",
              })}
            >
              {item.difficulty}
            </div>
            <div className={styles.topic}>{item.topic}</div>
            <div className={styles.labels}>
              {item.labels.map((label) => (
                <Tag bordered className={styles.tag}>
                  {label}
                </Tag>
              ))}
            </div>
          </div>
        ))}
      </div>
    </div>
  );
}

export default App;
