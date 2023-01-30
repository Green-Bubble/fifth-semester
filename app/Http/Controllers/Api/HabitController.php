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
        $dateString = $request->input('date');
        $date = date('Y-m-d',strtotime($dateString));

        $baseQuery = Habit::where('user_id',$user->id);
        
        if($dateString){
            $baseQuery->with(['day_marks' => fn($query) => $query->whereDate('mark_date','=',$date)]);
        } else {
            $baseQuery->with('day_marks');
        }

        Log::info($baseQuery->get()->toArray());

        return HabitResource::collection(Habit::where('user_id',$user->id)->get());
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
            $validated['user_id'] = $request->user()->id;

            Habit::create($validated);
    
            return response()->json($validated);
        } catch (Exception $e){
            Log::error($e);
        }
        
    }

    /**
     * Display the specified resource.
     *
     * @param  \App\Models\Habit  $habit
     * @return \Illuminate\Http\Response
     */
    public function show(Habit $habit)
    {

    }

    /**
     * Update the specified resource in storage.
     *
     * @param  \App\Http\Requests\UpdateHabitRequest  $request
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function update(UpdateHabitRequest $request, $id)
    {
        try{
            $validated = $request->validated();

            Log::info($request->all());

            $habit = Habit::find($id);
            $habit->update($validated);

            return response()->json($validated);
        } catch (Exception $e){
            Log::error($e);
        }
        
    }

    /**
     * Remove the specified resource from storage.
     *
     * @param  int  $id
     * @return \Illuminate\Http\Response
     */
    public function destroy(int $id)
    {
        Habit::find($id)->delete();

        return response()->json(['deleted_id' => $id]);
    }
}
