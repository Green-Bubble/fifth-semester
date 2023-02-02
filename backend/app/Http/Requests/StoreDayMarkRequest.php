<?php

namespace App\Http\Requests;


use Illuminate\Foundation\Http\FormRequest;
use Illuminate\Validation\Rule;

class StoreDayMarkRequest extends FormRequest
{
    /**
     * Determine if the user is authorized to make this request.
     *
     * @return bool
     */
    public function authorize()
    {
        return true;
    }

    /**
     * Get the validation rules that apply to the request.
     *
     * @return array<string, mixed>
     */
    public function rules()
    {
        return [
            'habit_id' => 'required|exists:habits,id',
            'mark_date' => 'required|date',
            'state' => [
                'required',
                Rule::in(['done','failed','skipped','value'])
            ],
            'value' => 'nullable|integer'
        ];
    }
}
