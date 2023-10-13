import './App.css'

interface Item {
  id: number;
  difficulty: string;
  topic: string;
  title: string;
  description: string;
  labels: string[];
}

const items: Item[] = [
  {id: 1, difficulty: "", topic: "", title: "Two Numbers", description: "", labels: []}
];

function App() {
  return (
    <>
    <div>LeetCode Solutions of CCC</div>
    {
      items.map(item => <div>{item.title}</div>)
    }
    </>
  )
}

export default App
