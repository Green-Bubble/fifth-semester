import { useRef, useState } from "react";
import axiosClient from "../axios-client";

export default function HabitForm(props){
    const typeRef = useRef();
    const colorRef =  useRef();
    const titleRef = useRef();
    const descriptionRef = useRef();
    const [frequencyState,setFrequency] = useState("everyday");
    const startHourRef = useRef();
    const endHourRef = useRef();

    function onFrequencyChange(ev){
        setFrequency(ev.target.value);
    }

    function createHabit(payload){
        axiosClient.post('/habit/store',payload)
        .then((response)=>{
            console.log(response);
        })
        .catch((error) => {

            console.log(error.response.data.errors); 
        })
    }

    function updateHabit(payload){
        axiosClient.put(`/habit/${props.habit.id}`,payload)
        .then((response)=>{
            console.log(response);
        })
        .catch((error) => {
            console.log(error.response.data.errors);
        })
        console.log(props.habit.id);
    }

    function onSubmit(ev){
        console.log(props);

        ev.preventDefault();

        const payload = {
            type: typeRef.current.value,
            color: colorRef.current.value,
            title: titleRef.current.value,
            description: descriptionRef.current.value,
            frequency: frequencyState,
            startHour: startHourRef.current.value,
            endHour: endHourRef.current.value,
        }

        if(props.habit === null) {
            console.log("CREATE HABIT");
            createHabit(payload);
        } else {
            console.log("UPDATE HABIT");
            updateHabit(payload);
        }
        
        console.log(payload);
        props.onSubmit();
    }



    return (
        <form onSubmit={onSubmit} className="hidden">
            <input ref={typeRef} type="hidden" name="type" value="positiveYN"></input>
            <input ref={colorRef} type="color" name="color"></input>
            <label htmlFor="title">Name</label>
            <input ref={titleRef} type="text" name="title" id="title" placeholder="e.g. Exercise"></input>
            <label htmlFor="description">Description</label>
            <input ref={descriptionRef} type="text" name="description" id="description" placeholder="e.g. Did I exercise today"></input>
            <div className="frequency">
                <label htmlFor="everyday">Everyday</label>
                <input onChange={onFrequencyChange} type="radio" name="frequency" id="everyday" value="everyday" defaultChecked></input>
                <label htmlFor="times-a-week">Some times per week</label>
                <input onChange={onFrequencyChange} type="radio" name="frequency" id="times-a-week" value="times-a-week"></input>
                <label htmlFor="every-each-day">Every some day</label>
                <input onChange={onFrequencyChange} type="radio" name="frequency" id="every-each-day" value="every-each-day"></input>
            </div>
            <label htmlFor="startShowHour">Show from</label>
            <input ref={startHourRef} type="time" name="startShowHour" id="startShowHour"></input>
            <label htmlFor="endShowHour">to</label>
            <input ref={endHourRef} type="time" name="endShowHour" id="endShowHour"></input>
            <input type="submit" name="submit" value="Save"></input>
        </form>
    )
}