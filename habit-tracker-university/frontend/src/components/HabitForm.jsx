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
        console.log("HABIT FORM PROPS",props);

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
        
        props.onSubmit();
    }

    return (
        <form onSubmit={onSubmit}>
            <input ref={typeRef} type="hidden" name="type" defaultValue={props.habit !== null ? props.habit.type : "positiveYN"}></input>
            <input ref={colorRef} type="color" name="color" defaultValue={props.habit !== null ? props.habit.color : ""}></input>
            <label htmlFor="title">Name</label>
            <input ref={titleRef} type="text" name="title" id="title" placeholder="e.g. Exercise" defaultValue={props.habit?.title ?? ""}></input>
            <label htmlFor="description">Description</label>
            <input ref={descriptionRef} type="text" name="description" id="description" placeholder="e.g. Did I exercise today" defaultValue={props.habit !== null ? props.habit.description : ""}></input>
            <div className="frequency"> 
                <label htmlFor="everyday">Everyday</label>
                <input onChange={onFrequencyChange} type="radio" name="frequency" id="everyday" value="everyday" defaultChecked={props.habit !== null ? props.habit.frequency === 'everyday' : true}></input>
                <label htmlFor="times-a-week">Some times per week</label>
                <input onChange={onFrequencyChange} type="radio" name="frequency" id="times-a-week" value="times-a-week" defaultChecked={props.habit !== null ? props.habit.frequency === 'times-a-week' : false}></input>
                <label htmlFor="every-each-day">Every some day</label>
                <input onChange={onFrequencyChange} type="radio" name="frequency" id="every-each-day" value="every-each-day" defaultChecked={props.habit !== null ? props.habit.frequency === 'every-each-day' : false}></input>
            </div>
            <label htmlFor="startShowHour">Show from</label>
            <input ref={startHourRef} type="time" name="startShowHour" id="startShowHour" defaultValue={props.habit !== null ? props.habit.startHour : ""}></input>
            <label htmlFor="endShowHour">to</label>
            <input ref={endHourRef} type="time" name="endShowHour" id="endShowHour" defaultValue={props.habit !== null ? props.habit.endHour : ""}></input>
            <input type="submit" name="submit" value={props.habit === null ? "Forge" : "Update"}></input>
        </form>
    )
}