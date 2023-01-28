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
            
            console.log("READ HABITS",response);
            setHabits(response.data.data);
            setIsLoading(false);
        })
        .catch((error) => {

            console.log(error.response.data.errors);
            setIsLoading(false);
        })
    }

    const onHabitClick = function(habit){
        console.log(habit);
        setIsHabitFormOpen(true);
        setUpdatedHabit(habit);
    }

    function funnySort(){
        function shuffle(array) {
            let currentIndex = array.length,  randomIndex;
            
            // While there remain elements to shuffle.
            while (currentIndex != 0) {
            
                // Pick a remaining element.
                randomIndex = Math.floor(Math.random() * currentIndex);
                currentIndex--;
            
                // And swap it with the current element.
                [array[currentIndex], array[randomIndex]] = [
                array[randomIndex], array[currentIndex]];
            }
            
            return array;
        }

        let huh = habits.slice();
        setHabits(shuffle(huh));
    }

    const updateHabit = function(habitId,payload){
        axiosClient.put(`/habit/${habitId}`,null)
        .then((response)=>{
            console.log(response);
        })
        .catch((error) => {
            console.log(error.response.data.errors);
        })
        console.log(habitId);
    }

    return (
        <div id="habits">
            <button
                onClick={funnySort}
            >
                Śmieszne sortowanko
            </button>
            <div className="habits-list">
                {habits.map(h => (
                    <Habit key={h.id} habit={h} onHabitClick={onHabitClick}/>
                ))}
            </div>
            <button 
                className={'slide ' + (isHabitFormOpen && 'hidden')}
                onClick={() => {
                    setIsHabitFormOpen(true);
                    setUpdatedHabit(null);
                }}
            >Open habit form</button>
            <div className={'habit-form slide ' + (!isHabitFormOpen && 'hidden')}>
                <button 
                    onClick={() => {setIsHabitFormOpen(false)}}
                >Close habit form</button>
                <HabitForm key={updatedHabit !== null ? updatedHabit.id : 0} habit={updatedHabit} onSubmit={getHabits} updateHabit={updateHabit}/>
            </div> 
        </div>
    )
}