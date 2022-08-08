#pragma once

namespace PCL_CLI {
	
	pin_ptr<float>^ float_2darray_conversion(array<float, 2>^ input) {
		pin_ptr<float> arrayPin = &input[0, 0];
		return arrayPin;
	}

	//void ChangeArray(array<array<int>^>^ arr) {
	//	using System::Runtime::InteropServices::GCHandle;
	//	using System::Runtime::InteropServices::GCHandleType;

	//	// pin each contained array<int>^
	//	array<GCHandle>^ pins = gcnew array<GCHandle>(arr->Length);
	//	for (int i = 0, i_max = pins->Length; i != i_max; ++i)
	//		pins[i] = GCHandle::Alloc(arr[i], GCHandleType::Pinned);

	//	try {
	//		// get int*s for each contained pinned array<int>^
	//		array<int*>^ arrays = gcnew array<int*>(pins->Length);
	//		for (int i = 0, i_max = arrays->Length; i != i_max; ++i)
	//			arrays[i] = static_cast<int*>(pins[i].AddrOfPinnedObject().ToPointer());

	//		// pin outer array<int*>^
	//		pin_ptr<int*> pin = &arrays[0];

	//		// pass outer pinned array<int*> to UNumeric::ChangeArray as an int**
	//		// (note that no casts are necessary in correct code)
	//		ChangeArray(pin, arrays->Length);
	//	}
	//	finally {
	//		// unpin each contained array<int>^
	//		for each (GCHandle pin in pins)
	//			pin.Free();
	//	}
	//}

	/*IntPtr Array3DToIntPtr(short[, , ] Val) {
		IntPtr ret = Marshal.AllocHGlobal((Val.GetLength(0) + Val.GetLength(1) + Val.GetLength(2)) * sizeof(short));

		int offset = 0;
		for (int i = 0; i < Val.GetLength(0); i++) {

			for (int j = 0; j < Val.GetLength(1); j++) {
				for (int k = 0; k < Val.GetLength(2); k++) {
					Marshal.WriteInt16(ret, offset, Val[i, j, k]);
					offset += sizeof(short);


				}
			}
		}

		return ret;
	}*/

}