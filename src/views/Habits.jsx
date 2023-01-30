import Icon from "@mdi/react";
import { mdiPlus, mdiCloseThick, mdiDelete} from '@mdi/js';
import { useEffect, useRef, useState } from "react";
import axiosClient from "../axios-client";
import Habit from "../components/Habit";
import HabitForm from "../components/HabitForm";
import DayPicker from "../components/DayPicker";
import {set,parse,format,isToday,addDays,subDays, isAfter, isBefore} from "date-fns";

export default function Habits(){

    const [updatedHabit,setUpdatedHabit] = useState(null);
    const [isLoading,setIsLoading] = useState(true);
    const [selectedDate,setSelectedDate] = useState(new Date());
    const [isHabitFormOpen,setIsHabitFormOpen] = useState(false);
    const [habits,setHabits] = useState([]);

    useEffect(() => {
        getHabits();
    },[]);

    function onSubmit(){
        getHabits();
        setIsHabitFormOpen(false);
    }

    function onDateChange(date){
        console.log("Selected date: ",date);
        setSelectedDate(date);
    }

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

    function deleteHabit(){
        axiosClient.delete(`/habit/${updatedHabit.id}`)
        .then((response)=>{
            console.log("DELETE HABIT",response);

        
            const indToDelete = habits.findIndex(habit => habit.id === response.data.deleted_id);
            const habitsWithoutDeleted = [...habits];
            habitsWithoutDeleted.splice(indToDelete,1);
            setHabits(habitsWithoutDeleted);

            setIsHabitFormOpen(false);
        })
        .catch((error) => {
            console.log(error.response.data.errors);
        })
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

    return (
        <div id="habits">
            <DayPicker selectedDate={selectedDate} onDateChange={onDateChange}/>
            <h3 className="selected-date">
            {
                isToday(selectedDate) ? "Today" : format(selectedDate,'yyyy.MM.dd')
            }
            </h3>
            <div className="habits-list">
                {habits.map(h => (
                    <Habit key={h.id} habit={h} onHabitClick={onHabitClick} selectedDate={selectedDate}/>
                ))}
            </div>
            <button 
                className={'create-habit-btn slide ' + (isHabitFormOpen && 'hidden')}
                onClick={() => {
                    setIsHabitFormOpen(true);
                    setUpdatedHabit(null);
                }}
            ><p>New habit</p>  <Icon path={mdiPlus} size={1.4}/></button>
            <div className={'habit-form slide ' + (!isHabitFormOpen && 'hidden')}>
                <button 
                    className="close"
                    onClick={() => {setIsHabitFormOpen(false)}}
                ><Icon path={mdiCloseThick} size={1.4}/></button>
                {updatedHabit && <button 
                    className="delete"
                    onClick={() => {deleteHabit()}}
                ><Icon path={mdiDelete} size={1.4}/></button>}
                <HabitForm key={updatedHabit !== null ? updatedHabit.id : 0} habit={updatedHabit} onSubmit={onSubmit}/>
            </div> 
        </div>
    )
}

/*<button
onClick={funnySort}
>
    Śmieszne sortowanko
</button>*/