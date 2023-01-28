import { useEffect, useRef, useState } from "react";
import axiosClient from "../axios-client";
import Habit from "./Habit";
import HabitForm from "./HabitForm";

export default function Habits(){

    const [updatedHabit,setUpdatedHabit] = useState(null);
    const [isLoading,setIsLoading] = useState(true);
    const [isHabitFormOpen,setIsHabitFormOpen] = useState(false);
    const [habits,setHabits] = useState([]);

    useEffect(() => {
        getHabits();
    },[]);

    const getHabits = function(){
        setIsLoading(true);
        axiosClient.post('/habits')
        .then((response)=>{
            console.log(response);

            setHabits(response.data.data);
            setIsLoading(false);
        })
        .catch((error) => {

            console.log(error.response.data.errors);
            setIsLoading(false);
        })
    }

    const editHabit = function(habitId){
        console.log(habitId);
    }

    return (
        <div id="habits">
            
            <div className="habits-list">
                {habits.map(h => (
                    <Habit key={h.id} habit={h} editHabit={editHabit}/>
                ))}
            </div>
            <button 
                className={'slide ' + (isHabitFormOpen && 'hidden')}
                onClick={() => {setIsHabitFormOpen(true)}}
            >Open habit form</button>
            <div className={'habit-form slide ' + (!isHabitFormOpen && 'hidden')}>
                <button 
                    onClick={() => {setIsHabitFormOpen(false)}}
                >Close habit form</button>
                <HabitForm habit={updatedHabit} onSubmit={getHabits}/>
            </div> 
        </div>
    )
}