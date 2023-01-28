<?php

namespace App\Http\Controllers\Api;

use App\Http\Controllers\Controller;
use App\Models\Habit;
use App\Http\Requests\StoreHabitRequest;
use App\Http\Requests\UpdateHabitRequest;
use App\Http\Resources\HabitResource;
use Exception;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Log;
use Illuminate\Validation\Rule;

class HabitController extends Controller
{
    /**
     * Display a listing of the resource.
     *
     * @return \Illuminate\Http\Response
     */
    public function index(Request $request)
    {
        $user = $request->user();
        return HabitResource::collection(Habit::orderBy('user_id','asc')->where('user_id',$user->id)->get());
    }

    /**
     * Store a newly created resource in storage.
     *
     * @param  \App\Http\Requests\StoreHabitRequest  $request
     * @return \Illuminate\Http\Response
     */
    public function store(StoreHabitRequest $request)
    {
        try {
            $validated = $request->validated();
            Log::info($validated);
            Habit::create([
                'user_id' => $request->user()->id,
                'type' => $request->input('type'),
                'color' => $request->input('color'),
                'title' => $request->input('title'),
                'description' => $request->input('description'),
                'frequency' => $request->input('frequency'),
                'startHour' => $request->input('startHour'),
                'endHour' => $request->input('endHour')
            ]);
    
            return response()->json($validated);
        } catch (Exception $e){
            Log::error($e);
        }
        
    }
/*
    return [
        'type' => [
            'required',
            Rule::in(['positiveYN'])
        ],
        'color' => 'required|regex:/^#[0-9a-fA-f]{6}$/',
        'title' => 'required|string|max:255',
        'description' => '',
        'frequency' => [
            'required',
            Rule::in(['everyday'])
        ],
        'startHour' => 'date_format:H:i',
        'endHour' => 'date_format:H:i|after:startHour'
    ];*/

    /**
     * Display the specified resource.
     *
     * @param  \App\Models\Habit  $habit
     * @return \Illuminate\Http\Response
     */
    public function show(Habit $habit)
    {
        //
    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \App\Http\Requests\UpdateHabitRequest  $request
     * @param  \App\Models\Habit  $habit
     * @return \Illuminate\Http\Response
     */
    public function update(UpdateHabitRequest $request, Habit $habit)
    {
        //
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  \App\Models\Habit  $habit
     * @return \Illuminate\Http\Response
     */
    public function destroy(Habit $habit)
    {
        //
    }
}
