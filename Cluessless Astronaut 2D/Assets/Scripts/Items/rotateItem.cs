using UnityEngine;
using System.Collections;

public class rotateItem : MonoBehaviour {

	public float rotSpeed;

	private Quaternion addQuaternions(Quaternion a, Quaternion b){
		return new Quaternion (a.x+b.x, a.y+b.y, a.z+b.z, a.w+b.w);
	}
	// Use this for initialization
	void Start () {
	}
	
	// Update is called once per frame
	void Update () {
	
	}

	void FixedUpdate(){

		this.transform.Rotate (0, 0, rotSpeed);
	}
}
